#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

typedef std::string str;

class Bureaucrat;

class PresidentialPardonForm: public Form
{
	private:
		str	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const str &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();

		str		getTarget()							  const;
		void	execute  (const Bureaucrat &executor) const;
		
		PresidentialPardonForm &operator =(const PresidentialPardonForm &copy);
};

#endif
