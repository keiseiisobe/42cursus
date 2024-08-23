#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	try
	{
	switch (argc)
	{
		case 2:
			ScalarConverter::convert(static_cast<string>(argv[1]));
			break;
		default:
			std::cout << "Note: ./convert [data]" << std::endl;
			break;
	}
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}
