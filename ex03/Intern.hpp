#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

typedef std::string str;

class Intern
{
	private:
		Form	*makePPF(str target) const;
		Form	*makeRRF(str target) const;
		Form	*makeSCF(str target) const;
		typedef Form *(Intern::*fp)(str target) const;
		
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Form	*makeForm(str name, str target) const;

		Intern &operator =(const Intern &copy);
};

#endif
