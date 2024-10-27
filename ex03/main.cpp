#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		Bureaucrat *a = new Bureaucrat("Promoted guy", 150);
		Intern *z = new Intern();
		Form *b = z->makeForm("SomeRandomForm", "Clown");
		b = z->makeForm("presidential pardon", "Clown");
		Form *d = z->makeForm("robotomy request", "Bender");
		Form *e = z->makeForm("shrubbery creation", "Christmas");

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
		delete z;
	}
	return (0);
}
