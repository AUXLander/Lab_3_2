//#include "Soution.h"

#include <iostream>
#include "Intera.h"
#include <math.h>
#include <algorithm>
 #include <immintrin.h>

/*

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(cli::array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab32::Soution form;
	Application::Run(% form);

	return 0;
}
*/

using value_type = double;
using integral = integral_t<value_type>;

constexpr size_t N = 100'000'000;

constexpr value_type a = 0.0;
constexpr value_type b = 1.0;

inline value_type f(const value_type rx) noexcept
{
	return 2.0 * std::cos(2.0 * rx) + 2.0;
}

int main() 
{
	const auto data = integral::generate_metrics(f, { a, 1.0 }, { b, 4.0 }, N);

	const auto result_NM = integral::Numeric(data.summ_max_fy, a, b, N);

	const auto ratio = static_cast<value_type>(data.entry_counts) / static_cast<value_type>(N);

	const auto result_v1 = integral::MonteCarlo_V1(a, b, data.ymin, data.ymax, ratio);
	const auto result_v2 = integral::MonteCarlo_V2(a, b, data.xmin, data.xmax, data.summ_fy, N);
	
	std::cout << result_NM << std::endl;
	std::cout << result_v1 << std::endl;
	std::cout << result_v2 << std::endl;

	return 0;
	//return system("pause");
}
