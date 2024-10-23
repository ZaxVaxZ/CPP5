#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

typedef std::string str;

class Form;

class Intern
{
	private:
		const str	_name;
		int			_grade;

	public:
		Intern();
		Intern(str name, int grade);
		Intern(const Intern &copy);
		~Intern();

		int		getGrade() const;
		str		getName () const;
		void	promote ();
		void	demote  ();
		void	signForm(Form &form) const;

		Intern &operator =(const Intern &copy);

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

std::ostream	&operator <<(std::ostream &o, const Intern &a);

#endif
