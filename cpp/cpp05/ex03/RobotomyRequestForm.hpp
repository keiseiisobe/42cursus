#ifndef ROBOTOMYREQUESTFORM_CPP
#define ROBOTOMYREQUESTFORM_CPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <random>

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm();
		void	execute(Bureaucrat const & executor) const;
};

#endif
