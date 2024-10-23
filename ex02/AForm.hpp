#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

typedef std::string str;

class Bureaucrat;

class AForm
{
	private:
		const str	_name;
		const int	_sign_grade;
		const int	_exec_grade;
		bool		_signed;

	public:
		AForm();
		AForm(const str &name, int sign_grade, int exec_grade);
		AForm(const AForm &copy);
		~AForm();

		str		getName			 () const;
		int		getSigningGrade  () const;
		int		getExecutionGrade() const;
		bool	getSigned		 () const;
		void	beSigned(const Bureaucrat &signer);
		void	beExecuted(const Bureaucrat &executor);

		AForm &operator =(const AForm &copy);

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

std::ostream	&operator <<(std::ostream &o, const AForm &a);

#endif
