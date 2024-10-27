#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5), _target("somewhere")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const str &target): Form("Presidential Pardon Form", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form("Presidential Pardon Form", 25, 5), _target(copy.getTarget())
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
