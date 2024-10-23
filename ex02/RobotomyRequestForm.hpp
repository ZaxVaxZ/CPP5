#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

typedef std::string str;

class Bureaucrat;

class RobotomyRequestForm
{
	private:
		const str	_name;
		const int	_sign_grade;
		const int	_exec_grade;
		bool		_signed;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const str &name, int sign_grade, int exec_grade);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		str		getName			 () const;
		int		getSigningGrade  () const;
		int		getExecutionGrade() const;
		bool	getSigned		 () const;
		void	beSigned(const Bureaucrat &signer);
		void	beExecuted(const Bureaucrat &executor);

		RobotomyRequestForm &operator =(const RobotomyRequestForm &copy);

		class GradeTooHighException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const throw();

		};
};

std::ostream	&operator <<(std::ostream &o, const RobotomyRequestForm &a);

#endif
