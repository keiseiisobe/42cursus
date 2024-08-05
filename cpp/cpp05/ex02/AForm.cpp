#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
	: name(""), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string fName, int fGradeToSign, int fGradeToExecute)
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

AForm::AForm(const AForm& f)
	: name(f.getName()), isSigned(f.getIsSigned()), gradeToSign(f.getGradeToSign()), gradeToExecute(f.getGradeToExecute())
{
}

AForm&	AForm::operator=(const AForm& f)
{
	(void)f;
	std::cout << "Form attribute is unchangable." << std::endl;
	return *this;
}

AForm::~AForm()
{
}

std::string	AForm::getName() const
{
	return name;
}

bool	AForm::getIsSigned() const
{
	return isSigned;
}

int		AForm::getGradeToSign() const
{
	return gradeToSign;
}

int		AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
}

void	AForm::check_requirement(const Bureaucrat& executor) const
{
	if (!isSigned || executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	return os << f.getName() << ", signed " << std::boolalpha << f.getIsSigned() << ", grade_to_sign " << f.getGradeToSign() << ", grade_to_execute " << f.getGradeToExecute();
}
