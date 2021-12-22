#pragma once
#include <algorithm>
#include <random>
#include <vector>
#include <tuple>
#include <time.h>

template<typename T>
using point_t = std::pair<T, T>;

template<typename T>
struct custom_point_t
{
	T x;
	T ry;
	T fy;

	custom_point_t() = default;

	custom_point_t(const T& x, const T& ry, const T& fy)
		: x(x), ry(ry), fy(fy)
	{;}
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

	static double min;
	static double max;

	static void generate_points(std::vector<point3f>& points, T(*f)(const T), const Point x0y0, const Point x1y1, const size_t N)
	{
		const auto [x0, y0] = x0y0;
		const auto [x1, y1] = x1y1;

		std::mt19937_64 GRN(std::random_device{}());
		std::uniform_real_distribution<> urd_Ox(x0, x1);
		std::uniform_real_distribution<> urd_Oy(y0, y1);

		points.resize(N);

		auto* p_data = points.data();

		T x;

		for (size_t index = 0; index < N; ++index)
		{
			x = urd_Ox(GRN);

			new (p_data + index) point3f(x, urd_Oy(GRN), f(x));
		}
	}

	static T Numeric(const std::vector<point3f>& points, const T a, const T b) noexcept
	{
		T square = 0.0;

		for (const auto& point : points)
		{
			square += std::max(point.fy, 0.0);
		}

		return static_cast<T>(b - a) * square / static_cast<T>(points.size());
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
		const auto x = points[0].x;

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

		min = x;
		max = x;

		for (const auto& point : points)
		{
			storage[(static_cast<size_t>(point.x < min) << 0U) | (static_cast<size_t>(point.x > max) << 1U)] = point.x;
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

	static T MonteCarlo_V1(const std::vector<point3f>& points, const T a, const T b)
	{
		const auto [min, max] = fMinfMaxY(points);
		const auto ratio = ratioIn(points);

		return (b - a) * (ratio * (max - min) + min);
	}

	static T MonteCarlo_V2(const std::vector<point3f>& points, const T a, const T b)
	{
		const auto [min, max] = fMinfMaxX(points);

		T summ = 0;

		for (const auto& point : points)
		{
			summ += point.fy;
		}

		return (max - min) * summ / static_cast<T>(points.size());
	}
};

