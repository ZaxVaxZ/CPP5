#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

typedef std::string str;

class Bureaucrat;

class Form
{
	private:
		const str	_name;
		const int	_sign_grade;
		const int	_exec_grade;
		bool		_signed;

	public:
		Form();
		Form(const str &name, int sign_grade, int exec_grade);
		Form(const Form &copy);
		~Form();

		str		getName			 () const;
		int		getSigningGrade  () const;
		int		getExecutionGrade() const;
		bool	getSigned		 () const;
		void	beSigned(const Bureaucrat &signer);

		Form &operator =(const Form &copy);

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

std::ostream	&operator <<(std::ostream &o, const Form &a);

#endif
