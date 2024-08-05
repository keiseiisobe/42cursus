#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		AForm();
		AForm(std::string fName, int fGradeToSign, int fGradeToExecute);
		AForm(const AForm&);
		AForm&	operator=(const AForm&);
		virtual ~AForm();
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			beSigned(const Bureaucrat& b);
		void			check_requirement(const Bureaucrat& executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
