#include "Soution.h"

#include <iostream>


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


/*
int main() {

	



	std::cout << Integral::Numeric(f, 0, 1, 100000) << std::endl;
	
	std::cout <<  << std::endl;
	//std::cout << "Min: " << Integral::min << std::endl;
	//std::cout << "Max: " << Integral::max << std::endl;

	system("pause");
	return 0;
}
*/