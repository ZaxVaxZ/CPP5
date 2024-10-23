#include "Intern.hpp"

Intern::Intern(): _name("Unnamed"), _grade(150)
{
	
}

Intern::Intern(str name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Intern::Intern(const Intern &copy): _name(copy.getName()), _grade(copy.getGrade())
{
	
}

str Intern::getName() const
{
	return _name;
}

int Intern::getGrade() const
{
	return _grade;
}

void Intern::promote()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Intern::demote()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Intern::signForm(Form &form) const
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

std::ostream &operator<<(std::ostream &o, const Intern &b)
{
	o << b.getName() << " is a Intern of grade " << b.getGrade();
	return o;
}

Intern &Intern::operator =(const Intern &copy)
{
	_grade = copy.getGrade();
	return *this;
}

Intern::~Intern()
{
	
}

const char *Intern::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Intern::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
