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
		std::cout << _name << " bureaucrat couldn't sign " << form.getName() << " as it has already been signed\n";
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed the " << form.getName() << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign the " << form.getName() << " because his " << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed the " << form.getName() << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << _name << " failed to execute the " << form.getName() << " due to " << e.what() << "\n";
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
	return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
