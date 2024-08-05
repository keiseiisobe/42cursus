#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
	: AForm(r)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	(void)r;
	std::cout << "Form attribute is unchangable." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	check_requirement(executor);
	std::random_device	r;
	std::default_random_engine	e(r());
	std::uniform_int_distribution<int>	uniform_dist(1, 6);
	int	mean = uniform_dist(e);
	if (mean % 2 == 0)
	{
		std::cout << "Beep boop..." << std::endl;
		std::cout << getName() << " has been robotomized successfully." << std::endl;
	}
	else
		std::cout << "The robotomy failed." << std::endl;
}
