#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		Bureaucrat *a = new Bureaucrat("Promoted guy", 150);
		AForm *b = new PresidentialPardonForm("Clown");
		AForm *d = new RobotomyRequestForm("Bender");
		AForm *e = new ShrubberyCreationForm("Christmas");

		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *d << std::endl;
		std::cout << *e << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(std::exception &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		Bureaucrat bur("Admin", 15);

		*a = bur;

		try
		{
			a->signForm(*e);
			a->signForm(*e);
			a->executeForm(*e);
			a->executeForm(*e);
			a->signForm(*d);
			a->signForm(*d);
			a->executeForm(*d);
			a->executeForm(*d);
			a->signForm(*b);
			a->signForm(*b);
			a->executeForm(*b);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		

		delete a;
		delete b;
		delete d;
		delete e;
	}
	return (0);
}
