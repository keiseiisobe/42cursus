#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class	Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		Form();
		Form(std::string fName, int fGradeToSign, int fGradeToExecute);
		Form(const Form&);
		Form&	operator=(const Form&);
		~Form();
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
