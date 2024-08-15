#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
	: name(""), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string fName, int fGradeToSign, int fGradeToExecute)
	: name(fName), isSigned(false), gradeToSign(fGradeToSign), gradeToExecute(fGradeToExecute)
{
	if (fGradeToSign < 1)
		throw GradeTooHighException();
	if (fGradeToSign > 150)
		throw GradeTooLowException();
	if (fGradeToExecute < 1)
		throw GradeTooHighException();
	if (fGradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& f)
	: name(f.getName()), isSigned(false), gradeToSign(f.getGradeToSign()), gradeToExecute(f.getGradeToExecute())
{
	std::cout << "Form has been successfully copied, but sign is false by default" << std::endl;
}

Form&	Form::operator=(const Form& f)
{
	(void)f;
	std::cout << "All elements are constant. Copy assignment failed." << std::endl;
	return *this;
}

Form::~Form()
{
}

std::string	Form::getName() const
{
	return name;
}

bool	Form::getIsSigned() const
{
	return isSigned;
}

int		Form::getGradeToSign() const
{
	return gradeToSign;
}

int		Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	return os << "form (name: " << f.getName() << ", signed: " << std::boolalpha << f.getIsSigned() << ", grade_to_sign: " << f.getGradeToSign() << ", grade_to_execute: " << f.getGradeToExecute() << ")";
}
