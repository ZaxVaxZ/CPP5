#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 72, 45), _target("somewhere")
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const str &target): Form("Robotomy Request Form", 72, 45), _target(target)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form("Robotomy Request Form", 72, 45), _target(copy.getTarget())
{
	srand(time(NULL));
}

str RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
	{
		std::cout << getName() << " must be signed to be executed!\n";
		return ;
	}
	if (executor.getGrade() > getExecutionGrade())
		throw GradeTooLowException();
	std::cout << "* Drilling noises *\n";
	if (rand() % 2 == 0)
		std::cout << _target << " robotomization has failed!\n";
	else
		std::cout << _target << " robotomized successfully!\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &copy)
{
	_target = copy.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}
