#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat()
	: name(""), grade(0)
{
}

Bureaucrat::Bureaucrat(std::string b_name, int b_grade)
	: name(b_name), grade(b_grade)
{
	if (b_grade < 1)
		throw GradeTooHighException();
	if (b_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
	: name(b.getName()), grade(b.getGrade())
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& b)
{
	(void)b;
	std::cout << "Bureaucrat attribute is unchangable." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::increment_grade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrement_grade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(AForm& f)
{
	f.beSigned(*this);
	if (f.getIsSigned())
		std::cout << *this << std::endl << "signed" << std::endl << f << std::endl;
	else
		std::cout << *this << std::endl << "couldn't signed" << std::endl << f << ", because of low grade" << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade();
}
