#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("keisei", 99);
		//Bureaucrat	b("keisei", 100);
		//Bureaucrat	b("keisei", 101);
		b.signForm(); // gradeToSign: 100
	}
	catch (std::exception& e)
	{
		std::cout << "error: Grade is out of range" << std::endl;
	}
}
