#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _name("Unnamed"),
	_sign_grade(150), _exec_grade(150), _signed(false)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const str &name, int sign_grade, int exec_grade): _name(name),
	_sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): _name(copy.getName()),
	_sign_grade(copy.getSigningGrade()), _exec_grade(copy.getExecutionGrade()), _signed(false)
{
	
}

str PresidentialPardonForm::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &f)
{
	o << f.getName() << " form has a signing grade of ";
	o << f.getSigningGrade() << " or higher, and an execution grade of ";
	o << f.getExecutionGrade() << " or higher";
	return o;
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &copy)
{
	(void) copy;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

int PresidentialPardonForm::getExecutionGrade() const
{
	return _exec_grade;
}

int PresidentialPardonForm::getSigningGrade() const
{
	return _sign_grade;
}

bool PresidentialPardonForm::getSigned() const
{
	return _signed;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &signer)
{
	if (_signed)
	{
		std::cout << "PresidentialPardonForm already signed!\n";
		return ;
	}
	if (signer.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
	std::cout << "PresidentialPardonForm signed!\n";
}

const char *PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
