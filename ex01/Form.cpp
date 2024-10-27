#include "Form.hpp"

Form::Form(): _name("Unnamed"),
	_sign_grade(150), _exec_grade(150), _signed(false)
{
	
}

Form::Form(const str &name, int sign_grade, int exec_grade): _name(name),
	_sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy): _name(copy.getName()),
	_sign_grade(copy.getSigningGrade()), _exec_grade(copy.getExecutionGrade()), _signed(false)
{
	
}

str Form::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	o << f.getName() << " form has a signing grade of ";
	o << f.getSigningGrade() << " or higher, and an execution grade of ";
	o << f.getExecutionGrade() << " or higher";
	return o;
}

Form &Form::operator =(const Form &copy)
{
	(void) copy;
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

bool Form::getSigned() const
{
	return _signed;
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (_signed)
	{
		std::cout << "Form already signed!\n";
		return ;
	}
	if (signer.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
	std::cout << "Form signed!\n";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
