//#include "Soution.h"

#include <iostream>
#include "Intera.h"
#include <math.h>
#include <algorithm>

inline double f(const double x) noexcept
{
	return 2 * cos(2 * x) + 2;
}
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
//constexpr size_t N = 1'000'000;

constexpr value_type a = 0.0;
constexpr value_type b = 1.0;



int main() 
{
	std::vector<integral::point3f> points;

	integral::generate_points(points, f, { a, 1.0 }, { b, 4.0 }, N);

	const auto result_NM = integral::Numeric(points, a, b);
	const auto result_v1 = integral::MonteCarlo_V1(points, a, b);
	const auto result_v2 = integral::MonteCarlo_V2(points, a, b);
	
	std::cout << result_NM << std::endl;
	std::cout << result_v1 << std::endl;
	std::cout << result_v2 << std::endl;

	return system("pause");
}
