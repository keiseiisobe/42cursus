#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
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
