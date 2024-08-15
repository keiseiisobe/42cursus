#include "Intern.hpp"
#include "AForm.hpp"

int	main()
{
	Intern	i;
	AForm	*af;

	try
	{
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
		std::cout << "RaspbberyCreationForm target: " << af->getName() << std::endl << std::endl;
		delete af;
	}
	catch (std::exception& e)
	{
	}
	return 0;
}

/* __attribute__((destructor)) */
/* static void	destructor() */
/* { */
/* 	system("leaks -q a.out"); */
/* } */
