#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include "Bureaucrat.hpp"
#include "Form.hpp"

typedef std::string str;

class Bureaucrat;

class RobotomyRequestForm: public Form
{
	private:
		str	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const str &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		str		getTarget()							  const;
		void	execute  (const Bureaucrat &executor) const;
		
		RobotomyRequestForm &operator =(const RobotomyRequestForm &copy);
};

#endif
