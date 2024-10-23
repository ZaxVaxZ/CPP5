#include "Form.hpp"

Form::Form(): _name("Some Form"),
	_sign_grade(150), _exec_grade(150)
{
	
}

Form::Form(const str &name, int sign_grade, int exec_grade): _name(name),
	_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy): _name(copy.getName()),
	_sign_grade(150), _exec_grade(150)
{
	
}

str Form::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	o << f.getName() << " is a Form. It must be signed by a grade ";
	o << f.getSigningGrade() << " or higher, and executed by a grade ";
	o << f.getExecutionGrade() << " or higher";
	return o;
}

Form &Form::operator =(const Form &copy)
{
	return *this;
}

Form::~Form()
{
	
}

int Form::getExecutionGrade() const
{
	return _exec_grade;
}

int Form::getSigningGrade() const
{
	return _sign_grade;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
