#pragma once
#include <algorithm>
#include <random>
#include <vector>
#include <tuple>
#include <time.h>
#include <omp.h>
//#include <immintrin.h>

template<typename T>
using point_t = std::pair<T, T>;

template<typename T>
struct custom_point_t
{
	T rx;
	T ry;
	T fy;

	custom_point_t() = default;

	custom_point_t(const T& rx, const T& ry, const T& fy)
		: rx(rx), ry(ry), fy(fy)
	{;}
};

template <typename T>
struct metrics_t
{
	T summ_fy;
	T summ_max_fy;

	size_t entry_counts;

	T xmin;
	T xmax;

	T ymin;
	T ymax;
};

template <typename T>
union data_split
{
	T storage[3];

	struct
	{
		T val;
		T min;
		T max;
	};
};

template <typename T>
class integral_t
{
	static unsigned int getSeed(void) 
	{
		return time(NULL);
	}
public:
	using Point = point_t<T>;
	using point3f = custom_point_t<T>;
	using metrics = metrics_t<T>;

	static double min;
	static double max;

	static int generate_points(std::vector<point3f>& points, T(*f)(const T), const Point x0y0, const Point x1y1, const size_t N)
	{
		const auto [x0, y0] = x0y0;
		const auto [x1, y1] = x1y1;

		std::mt19937_64 GRN(std::random_device{}());
		std::uniform_real_distribution<> urd_Ox(x0, x1);
		std::uniform_real_distribution<> urd_Oy(y0, y1);

		points.resize(N);

		auto* p_data = points.data();

		constexpr T inc_rand_max = 1.0 / static_cast<T>(UINT32_MAX);

		constexpr int iN = 16; // omp_get_num_threads()
		const int jN = N / iN;

		#pragma omp parallel
		{
			#pragma omp for
			for (int i = 0; i < iN; ++i)
			{
				T rx, y;

				for (int j = 0; j < jN; ++j)
				{
					rx = urd_Ox(GRN);

					new (p_data + (i * jN) + j) point3f(rx, urd_Oy(GRN), f(rx));
				}
			}
		}

		return 0;
	}


	static T Numeric(const T square, const T a, const T b, const size_t N) noexcept
	{
		return static_cast<T>(b - a) * square / static_cast<T>(N);
	}

	static T Numeric(const std::vector<point3f>& points, const T a, const T b) noexcept
	{
		T square = 0.0;
	
		for (const auto& point : points)
		{
			square += std::max(point.fy, 0.0);
		}

		return Numeric(square, a, b, points.size());
	}

	static std::pair<T,T> fMinfMaxY(const std::vector<point3f>& points)
	{
		const auto y = points[0].fy;

		union
		{
			T storage[3]; // fy min max

			struct
			{
				T val; // 0
				T min; // 1
				T max; // 2
			};
		};

		min = y;
		max = y;

		for (const auto& point : points)
		{
			storage[(static_cast<size_t>(point.fy < min) << 0U) | (static_cast<size_t>(point.fy > max) << 1U)] = point.fy;
		}

		return std::make_pair(min, max);
	}

	static std::pair<T, T> fMinfMaxX(const std::vector<point3f>& points)
	{
		const auto rx = points[0].rx;

		union
		{
			T storage[3]; // x min max

			struct
			{
				T val; // 0
				T min; // 1
				T max; // 2
			};
		};

		min = rx;
		max = rx;

		for (const auto& point : points)
		{
			storage[(static_cast<size_t>(point.rx < min) << 0U) | (static_cast<size_t>(point.rx > max) << 1U)] = point.rx;
		}

		return std::make_pair(min, max);
	}

	static T ratioIn(const std::vector<point3f>& points)
	{
		size_t __entry_counts = 0;

		for (const auto& point : points)
		{
			__entry_counts += static_cast<size_t>(point.ry <= point.fy);
		}

		return static_cast<T>(__entry_counts) / static_cast<T>(points.size());
	}

	static T MonteCarlo_V1(const T a, const T b, const T f_ymin, const T f_ymax, const T ratio)
	{
		return (b - a) * (ratio * (f_ymax - f_ymin) + f_ymin);
	}

	static T MonteCarlo_V1(const std::vector<point3f>& points, const T a, const T b)
	{
		const auto [ymin, ymax] = fMinfMaxY(points);
		const auto ratio = ratioIn(points);

		return MonteCarlo_V1(a, b, ymin, ymax, ratio);
	}

	static T MonteCarlo_V2(const T a, const T b, const T xmin, const T xmax, const T summ, const size_t N)
	{
		return (xmin - xmin) * summ / static_cast<T>(N);
	}

	static T MonteCarlo_V2(const std::vector<point3f>& points, const T a, const T b)
	{
		const auto [xmin, xmax] = fMinfMaxX(points);

		T summ = 0;
		for (const auto& point : points)
		{
			summ += point.fy;
		}

		return MonteCarlo_V2(a, b, xmin, xmax, summ, N);
	}
};

