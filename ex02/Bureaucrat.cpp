#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unnamed"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(str name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _grade(copy.getGrade())
{
	
}

str Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::promote()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::demote()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	if (form.getSigned())
	{
		std::cout << _name << " bureaucrat couldn't sign " << form.getName() << " form as it has already been signed\n";
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed the " << form.getName() << " form\n";
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign the " << form.getName() << " form\n";
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << " is a Bureaucrat of grade " << b.getGrade();
	return o;
}

Bureaucrat &Bureaucrat::operator =(const Bureaucrat &copy)
{
	_grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
