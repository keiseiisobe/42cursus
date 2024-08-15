#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		//Bureaucrat	b("keisei", 0);
		Bureaucrat	b("keisei", 1);
		//Bureaucrat	b("keisei", 150);
		//Bureaucrat	b("keisei", 151);
		std::cout << b << std::endl;
		//b.increment_grade();
		b.decrement_grade();
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "error: Grade is out of range" << std::endl;
	}
}
