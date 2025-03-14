#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::string;

class	Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& i);
		Intern&	operator=(const Intern& i);
		class MatchError : public std::exception {};
		AForm*	makeForm(string form_name, string target);
};
