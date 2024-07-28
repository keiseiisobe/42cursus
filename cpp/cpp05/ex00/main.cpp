#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("keisei", 150);
		std::cout << b << std::endl;
		b.decrement_grade();
	}
	catch (std::exception& e)
	{
		std::cerr << "error" << std::endl;
	}
}
