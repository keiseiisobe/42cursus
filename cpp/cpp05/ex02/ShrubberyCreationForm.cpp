#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
	: AForm(s)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	(void)s;
	std::cout << "Form attribute is unchangable." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	check_requirement(executor);
	std::string		filename = getName().append("_shrubbery");
	std::ofstream	ostrm(filename);
	ostrm <<
"     @@@\n\
  @@@@@@@@@\n\
 @@@@@@@@@@@\n\
 @@@@@@@@@@@\n\
  @@@@@@@@@\n\
     |||\n\
     |||\n\
    /|||\\\n\
   //|||\\\\\n\
  /\\/\\/\\/\\/\\"
	<< std::endl;
	ostrm.close();
}
