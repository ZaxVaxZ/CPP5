#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Form *Intern::makeForm(str name, str target) const
{
	(void) name;
	(void) target;
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
