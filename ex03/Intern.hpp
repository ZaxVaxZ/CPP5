#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

typedef std::string str;

class Intern
{
	private:
		str	form_names[3];
		
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();


		Form	*makeForm(str name, str target) const;

		Intern &operator =(const Intern &copy);
};

#endif
