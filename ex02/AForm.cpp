#include "AForm.hpp"

AForm::AForm(): _name("Unnamed"),
	_sign_grade(150), _exec_grade(150), _signed(false)
{
	
}

AForm::AForm(const str &name, int sign_grade, int exec_grade): _name(name),
	_sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy): _name(copy.getName()),
	_sign_grade(copy.getSigningGrade()), _exec_grade(copy.getExecutionGrade()), _signed(false)
{
	
}

str AForm::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << f.getName() << " has a signing grade of ";
	o << f.getSigningGrade() << " or higher, and an execution grade of ";
	o << f.getExecutionGrade() << " or higher";
	return o;
}

AForm &AForm::operator =(const AForm &copy)
{
	(void) copy;
	return *this;
}

AForm::~AForm()
{
	
}

int AForm::getExecutionGrade() const
{
	return _exec_grade;
}

int AForm::getSigningGrade() const
{
	return _sign_grade;
}

bool AForm::getSigned() const
{
	return _signed;
}

void AForm::beSigned(const Bureaucrat &signer)
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
