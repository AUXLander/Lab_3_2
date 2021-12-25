#pragma once
#include <algorithm>
#include <random>
#include <vector>
#include <tuple>
#include <time.h>
#include <omp.h>
#include <immintrin.h>
#include <array>

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
struct alignas(T) metrics_t
{
	T xmin;
	T xmax;

	T ymin;
	T ymax;

	T summ_fy;
	T summ_max_fy;

	uint64_t entry_counts;
};

template <typename T>
union data_split_3
{
	T storage[3];

	struct
	{
		T val;
		T min;
		T max;
	};

	inline T& extremum(const T& value) noexcept
	{
		const size_t hash = (static_cast<size_t>(value < min) << 0U) |
			(static_cast<size_t>(value > max) << 1U);
		return storage[hash] = value;
	}
};

template <typename T>
union data_split_2
{
	T storage[2];

	struct
	{
		T def;
		T value;
	};

	inline T& max(const T& v) noexcept
	{
		return storage[static_cast<size_t>(v > value)] = v;
	}

	inline T& min(const T& v) noexcept
	{
		return storage[static_cast<size_t>(v < value)] = v;
	}
};

// Сумма компонент, горизонтальная сумма
inline double hsum(const __m256d& v)
{
	// берем младшие 128 бит
	__m128d vlow = _mm256_castpd256_pd128(v);
	// берем старшие 128 бит
	__m128d vhigh = _mm256_extractf128_pd(v, 1);

	// получаем две пары сумм
	vlow = _mm_add_pd(vlow, vhigh);

	__m128d high64 = _mm_unpackhi_pd(vlow, vlow);

	// складываем еще две пары
	return _mm_cvtsd_f64(_mm_add_sd(vlow, high64));
}

// Максимум компонент, горизонтальный максимум
inline double hmax(const __m256d& x)
{
	// переставляем пары компонент
	__m256d y = _mm256_permute2f128_pd(x, x, 1);
	// берем максимум в каждой паре
	__m256d m1 = _mm256_max_pd(x, y);

	// переставляем пары компонент
	__m256d m2 = _mm256_permute_pd(m1, 5);
	// берем максимум в каждой паре
	__m256d m = _mm256_max_pd(m1, m2);

	return m.m256d_f64[0];
}


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

	static metrics generate_metrics(__m256d(*f)(const __m256d), const Point x0y0, const Point x1y1, const size_t N)
	{
		const auto [x0, y0] = x0y0;
		const auto [x1, y1] = x1y1;

		std::mt19937_64 GRN(std::random_device{}());
		std::uniform_real_distribution<T> urd_Ox(x0, x1);
		std::uniform_real_distribution<T> urd_Oy(y0, y1);

		constexpr int iN = 16; // omp_get_num_threads()
		const int jN = static_cast<int>(N) / iN;
		const int jN_4 = jN >> 2U;

		std::array<metrics, iN> thread_storage;

#pragma omp parallel
		{
#pragma omp for
			for (int i = 0; i < iN; ++i)
			{
				const auto thidx = static_cast<size_t>(omp_get_thread_num());

				metrics& data = thread_storage[thidx];

				data.summ_fy = 0.0;
				data.summ_max_fy = 0.0;

				data.xmax = (x1 - x1) * 0.5;
				data.xmin = (x1 - x1) * 0.5;

				data.ymax = (y1 - y1) * 0.5;
				data.ymin = (y1 - y1) * 0.5;

				data.entry_counts = 0;

				data_split_2<T> ymax = { 0,0 };
				data_split_3<T> x = { 0,0,0 };
				data_split_3<T> y = { 0,0,0 };

				__m256d rx;
				__m256d ry;
				__m256d fy;

				constexpr __m256d dbl = { 2.0 , 2.0 , 2.0 , 2.0 };
				constexpr __m256d zero = { 0.0 , 0.0 , 0.0 , 0.0 };

				for (int j = 0; j < jN_4; ++j)
				{
					// Укладываем сгенерированные значения в 256 битные регистры
					rx = _mm256_set_pd(urd_Ox(GRN), urd_Ox(GRN), urd_Ox(GRN), urd_Ox(GRN));
					ry = _mm256_set_pd(urd_Oy(GRN), urd_Oy(GRN), urd_Oy(GRN), urd_Oy(GRN));

					fy = f(rx);

					x.extremum(hmax(rx));
					y.extremum(hmax(fy));

					// горизонтальная сумма
					data.summ_fy += hsum(fy);

					// сумма отличных от нуля компонент
					data.summ_max_fy += hsum(_mm256_max_pd(zero, fy));

					// Проводим сравнение
					auto notshifted = _mm256_cvtpd_epi32(_mm256_cmp_pd(ry, fy, _CMP_LE_OS));

					auto fgf1 = _mm_srli_epi32(notshifted, 31);

					auto dsa = _mm_hadd_epi32(fgf1, fgf1);
					auto dsa2 = _mm_hadd_epi32(dsa, dsa);

					data.entry_counts += dsa2.m128i_u32[0];
				}

				data.xmax = x.max;
				data.xmin = x.min;

				data.ymax = y.max;
				data.ymin = y.min;
			}
		}

		metrics& data = thread_storage[0];

		data_split_2<T> xmax = { 0,0 };
		data_split_2<T> xmin = { 0,0 };
		data_split_2<T> ymax = { 0,0 };
		data_split_2<T> ymin = { 0,0 };

		for (size_t i = 1; i < iN; ++i)
		{
			data.xmax = xmax.max(thread_storage[i].xmax);
			data.ymax = ymax.max(thread_storage[i].ymax);

			data.xmin = xmin.min(thread_storage[i].xmin);
			data.ymin = ymin.min(thread_storage[i].ymin);

			data.summ_fy += thread_storage[i].summ_fy;
			data.summ_max_fy += thread_storage[i].summ_max_fy;
			data.entry_counts += thread_storage[i].entry_counts;
		}

		return data;
	}

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


	inline static T Numeric(const T square, const T a, const T b, const size_t N) noexcept
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

	inline static T MonteCarlo_V1(const T a, const T b, const T f_ymin, const T f_ymax, const T ratio)
	{
		return (b - a) * (f_ymax - f_ymin) * ratio + f_ymin;
	}

	static T MonteCarlo_V1(const std::vector<point3f>& points, const T a, const T b)
	{
		const auto [ymin, ymax] = fMinfMaxY(points);
		const auto ratio = ratioIn(points);

		return MonteCarlo_V1(a, b, ymin, ymax, ratio);
	}

	inline static T MonteCarlo_V2(const T xmin, const T xmax, const T summ, const size_t N)
	{
		return (xmax - xmin) * summ / static_cast<T>(N);
	}

	static T MonteCarlo_V2(const std::vector<point3f>& points, const T a, const T b)
	{
		const auto [xmin, xmax] = fMinfMaxX(points);

		T summ = 0;
		for (const auto& point : points)
		{
			summ += point.fy;
		}

		return MonteCarlo_V2(xmin, xmax, summ, points.size());
	}
};

