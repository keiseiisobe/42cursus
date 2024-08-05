#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("", 5);
		std::cout << "------ShrubberyCreationForm------" << std::endl;
		ShrubberyCreationForm	s(b.getName());
		b.signForm(s);
		b.executeForm(s);
		std::cout << "---------------------------------" << std::endl;
		std::cout << "-------RobotomyRequestForm-------" << std::endl;
		RobotomyRequestForm	r(b.getName());
		b.signForm(r);
		b.executeForm(r);
		std::cout << "---------------------------------" << std::endl;
		std::cout << "------PresidentialPardonForm------" << std::endl;
		PresidentialPardonForm	p(b.getName());
		b.signForm(p);
		b.executeForm(p);
		std::cout << "----------------------------------" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "error" << std::endl;
	}
}
