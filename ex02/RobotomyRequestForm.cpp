#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _name("Unnamed"),
	_sign_grade(150), _exec_grade(150), _signed(false)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const str &name, int sign_grade, int exec_grade): _name(name),
	_sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): _name(copy.getName()),
	_sign_grade(copy.getSigningGrade()), _exec_grade(copy.getExecutionGrade()), _signed(false)
{
	
}

str RobotomyRequestForm::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &f)
{
	o << f.getName() << " form has a signing grade of ";
	o << f.getSigningGrade() << " or higher, and an execution grade of ";
	o << f.getExecutionGrade() << " or higher";
	return o;
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &copy)
{
	(void) copy;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

int RobotomyRequestForm::getExecutionGrade() const
{
	return _exec_grade;
}

int RobotomyRequestForm::getSigningGrade() const
{
	return _sign_grade;
}

bool RobotomyRequestForm::getSigned() const
{
	return _signed;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &signer)
{
	if (_signed)
	{
		std::cout << "RobotomyRequestForm already signed!\n";
		return ;
	}
	if (signer.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
	std::cout << "RobotomyRequestForm signed!\n";
}

const char *RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
