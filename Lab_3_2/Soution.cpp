#include <iostream>
#include "Intera.h"
#include <math.h>
#include <algorithm>
 #include <immintrin.h>

using value_type = double;
using integral = integral_t<value_type>;

inline __m256d f(const __m256d rx) noexcept
{
	constexpr __m256d dbl = { (2.0) , (2.0) , (2.0) , (2.0) };

	return _mm256_add_pd(_mm256_mul_pd(_mm256_cos_pd(_mm256_mul_pd(rx, dbl)), dbl), dbl);
}

int main() 
{
	constexpr size_t N = 100'000'000;

	constexpr value_type a = 0.0;
	constexpr value_type b = 1.0;

	const auto data = integral::generate_metrics(f, { a, 1.0 }, { b, 4.0 }, N);

	const auto result_NM = integral::Numeric(data.summ_max_fy, a, b, N);

	const auto ratio = static_cast<value_type>(data.entry_counts) / static_cast<value_type>(N);

	const auto result_v1 = integral::MonteCarlo_V1(a, b, data.ymin, data.ymax, ratio);
	const auto result_v2 = integral::MonteCarlo_V2(data.xmin, data.xmax, data.summ_fy, N);
	
	std::cout << result_NM << std::endl;
	std::cout << result_v1 << std::endl;
	std::cout << result_v2 << std::endl;

	return 0;
	//return system("pause");
}
