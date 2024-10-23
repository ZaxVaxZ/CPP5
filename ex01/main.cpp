#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat someone;
	Bureaucrat ej("Emad", 149);
	Bureaucrat emad(ej);
	Bureaucrat pierce("Pierce", 2);

	std::cout << someone << "\n";
	std::cout << ej << "\n";
	std::cout << emad << "\n";
	std::cout << pierce << "\n";

	try
	{
		Bureaucrat high("test", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		Bureaucrat low("test", 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		someone.demote();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	ej.demote();
	try
	{
		ej.demote();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	emad = pierce;
	emad.promote();
	try
	{
		emad.promote();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}
