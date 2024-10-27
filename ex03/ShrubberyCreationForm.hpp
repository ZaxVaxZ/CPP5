#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

typedef std::string str;

class Bureaucrat;

class ShrubberyCreationForm: public Form
{
	private:
		str	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const str &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		str		getTarget()							  const;
		void	execute  (const Bureaucrat &executor) const;
		
		ShrubberyCreationForm &operator =(const ShrubberyCreationForm &copy);
};

#endif
