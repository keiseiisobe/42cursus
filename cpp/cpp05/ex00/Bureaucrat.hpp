#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string b_name, int b_grade);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat&	operator=(const Bureaucrat&);
		~Bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		void		increment_grade();
		void		decrement_grade();
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
