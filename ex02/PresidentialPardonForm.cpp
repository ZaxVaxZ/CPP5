#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), _target("someone")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const str &target): AForm("Presidential Pardon Form", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm("Presidential Pardon Form", 25, 5), _target(copy.getTarget())
{
	
}

str PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
	{
		std::cout << getName() << " must be signed to be executed!\n";
		return ;
	}
	if (executor.getGrade() > getExecutionGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &copy)
{
	_target = copy.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}
