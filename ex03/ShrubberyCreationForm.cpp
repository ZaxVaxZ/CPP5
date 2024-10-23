#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _name("Unnamed"),
	_sign_grade(150), _exec_grade(150), _signed(false)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const str &name, int sign_grade, int exec_grade): _name(name),
	_sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): _name(copy.getName()),
	_sign_grade(copy.getSigningGrade()), _exec_grade(copy.getExecutionGrade()), _signed(false)
{
	
}

str ShrubberyCreationForm::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &f)
{
	o << f.getName() << " form has a signing grade of ";
	o << f.getSigningGrade() << " or higher, and an execution grade of ";
	o << f.getExecutionGrade() << " or higher";
	return o;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &copy)
{
	(void) copy;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

int ShrubberyCreationForm::getExecutionGrade() const
{
	return _exec_grade;
}

int ShrubberyCreationForm::getSigningGrade() const
{
	return _sign_grade;
}

bool ShrubberyCreationForm::getSigned() const
{
	return _signed;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &signer)
{
	if (_signed)
	{
		std::cout << "ShrubberyCreationForm already signed!\n";
		return ;
	}
	if (signer.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
	std::cout << "ShrubberyCreationForm signed!\n";
}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
