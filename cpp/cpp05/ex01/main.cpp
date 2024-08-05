#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("keisei", 15);
		b.signForm();
	}
	catch (std::exception& e)
	{
		std::cerr << "error" << std::endl;
	}
}
