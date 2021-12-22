//#include "Soution.h"

#include <iostream>
#include "Intera.h"
#include <math.h>
#include <algorithm>

double f(double x) {
	return 2 * cos(2 * x) + 2;
}
double F(double x) {
	return sin(2 * x) + 2 * x;
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

constexpr size_t N = 1'000'000;

int main() 
{
	std::vector<point> squareStairs = Integral::squareStairs(f, 0.0, 1.0, N);
	double result_NM = Integral::Numeric(f, 0.0, 1.0, N);

	std::vector<point> uniformSquare = Integral::uniformRandomOnSquare({ 0.0, 1.0 }, { 1.0, 4.0 }, N);
	double ratio_v1 = Integral::ratioIn(f, uniformSquare);
	double result_v1 = Integral::MonteCarlo_V1(f, 0.0, 1.0, uniformSquare);
	
	std::vector<double> uniformLine = Integral::uniformRandomOnLine(0.0, 1.0, N);
	double result_v2 = Integral::MonteCarlo_V2(f, uniformLine);
	
	std::cout << result_NM << std::endl;
	std::cout << result_v1 << std::endl;
	std::cout << result_v2 << std::endl;

	return 0;
}
