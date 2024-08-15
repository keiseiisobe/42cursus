#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& i)
{
	(void)i;
}

Intern&	Intern::operator=(const Intern& i)
{
	(void)i;
	return *this;
}

AForm	*Intern::makeForm(string form_name, string target)
{
	std::string	form_types[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	num_of_types = sizeof(form_types) / sizeof(form_types[0]);
	int	i = 0;
	for (;i < num_of_types;i++)
	{
		if (form_types[i] == form_name)
			break;
	}
	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << form_name << "." << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << form_name << "." << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << form_name << "." << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cerr << "Doesn't match any form." << std::endl;
			return nullptr; // should avoid nullptr ? (p.1039)
	}
}
