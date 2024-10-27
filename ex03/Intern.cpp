#include "Intern.hpp"

Form *Intern::makePPF(str target) const
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeRRF(str target) const
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makeSCF(str target) const
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern()
{
	
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Form *Intern::makeForm(str name, str target) const
{
	str	form_names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	fp	form_funcs[3] = {&Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF};
	for (int i = 0; i < 3; i++)
	{
		if (form_names[i] == name)
			return (this->*form_funcs[i])(target);
	}
	std::cerr << "No form found with that name!\n";
	return NULL;
}

Intern &Intern::operator =(const Intern &copy)
{
	(void) copy;
	return *this;
}

Intern::~Intern()
{
	
}
