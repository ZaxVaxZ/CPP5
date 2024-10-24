#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat ej("Emad", 128);
	Bureaucrat pi("Pierce", 32);

	std::cout << ej << "\n";
	std::cout << pi << "\n";

	Form smth;
	Form immi("immigration", 64, 3);
	Form fcpy(immi);



	std::cout << smth << "\n";
	std::cout << immi << "\n";
	std::cout << fcpy << "\n";

	try
	{
		Form t1("test", 190, 20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		Form t2("test", -90, 20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		Form t3("test", 90, -20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		Form t5("test", 90, 220);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	smth.beSigned(ej);
	smth.beSigned(pi);
	try
	{
		immi.beSigned(ej);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	
	immi.beSigned(pi);

	pi.signForm(fcpy);
	pi.signForm(fcpy);
}
