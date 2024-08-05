#include "Intern.hpp"
#include "AForm.hpp"

int	main()
{
	Intern	i;
	AForm	*af;

	af = i.makeForm("shrubbery creation", "keisei");
	std::cout << "ShrubberyCreationForm target: " << af->getName() << std::endl << std::endl;
	delete af;
	af = i.makeForm("robotomy request", "sato");
	std::cout << "RobotomyRequestForm target: " << af->getName() << std::endl << std::endl;
	delete af;
	af = i.makeForm("presidential pardon", "tanaka");
	std::cout << "PresidentialPardonForm target: " << af->getName() << std::endl << std::endl;
	delete af;
	af = i.makeForm("raspbbery creation", "yamada");
	delete af;
}
/*
__attribute__((destructor))
static void	destructor()
{
	system("leaks -q a.out");
}
*/
