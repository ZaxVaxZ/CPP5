#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), _target("somewhere")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const str &target): AForm("Shrubbery Creation Form", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm("Shrubbery Creation Form", 145, 137), _target(copy.getTarget())
{
	
}

str ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	wrf;

	if (!getSigned())
	{
		std::cout << getName() << " must be signed to be executed!\n";
		return ;
	}
	if (executor.getGrade() > getExecutionGrade())
		throw GradeTooLowException();
	wrf.open(_target + "_shrubbery", std::ios_base::app);
	if (!wrf)
	{
		std::cerr << "Error: File couldn't be created or appended to.\n";
		return ;
	}
    wrf << "                                                     .\n";
    wrf << "                                          .         ;\n";
    wrf << "             .              .              ;%     ;;\n";
    wrf << "               ,           ,                :;%  %;\n";
    wrf << "                :         ;                   :;%;'     .,\n";
    wrf << "       ,.        %;     %;            ;        %;'    ,;\n";
    wrf << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
    wrf << "          %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
    wrf << "           ;%;      %;        ;%;        % ;%;  ,%;'\n";
    wrf << "            `%;.     ;%;     %;'         `;%%;.%;'\n";
    wrf << "             `:;%.    ;%%. %@;        %; ;@%;%'\n";
    wrf << "                `:%;.  :;bd%;          %;@%;'\n";
    wrf << "                  `@%:.  :;%.         ;@@%;'\n";
    wrf << "                    `@%.  `;@%.      ;@@%;\n";
    wrf << "                      `@%%. `@%%    ;@@%;\n";
    wrf << "                        ;@%. :@%%  %@@%;\n";
    wrf << "                          %@bd%%%bd%%:;\n";
    wrf << "                            #@%%%%%:;;\n";
    wrf << "                            %@@%%%::;\n";
    wrf << "                            %@@@%(o);  . '\n";
    wrf << "                            %@@@o%;:(.,'\n";
    wrf << "                        `.. %@@@o%::;\n";
    wrf << "                           `)@@@o%::;\n";
    wrf << "                            %@@(o)::;\n";
    wrf << "                           .%@@@@%::;\n";
    wrf << "        \\  /               ;%@@@@%::;.\n";
    wrf << "        \\()               ;%@@@@%%:;;;.\n";
    wrf << "         ||           ...;%@@@@@%%:;;;;,..\n";
	wrf.close();
	std::cout << "Shrubbery created at " << _target << "\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &copy)
{
	_target = copy.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}
