#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

typedef std::string str;

class Form;

class Bureaucrat
{
	private:
		const str	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(str name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		int		getGrade() const;
		str		getName () const;
		void	promote ();
		void	demote  ();
		void	signForm(Form &form) const;
		void	executeForm(Form const &form) const;

		Bureaucrat &operator =(const Bureaucrat &copy);

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

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &a);

#endif
