#include "ScalarConverter.hpp"


int	main(int argc, char **argv)
{
//	std::cout << static_cast<float>(std::numeric_limits<int>::max()) << std::endl;
//	std::cout << static_cast<float>(std::numeric_limits<int>::min()) << std::endl;
//	std::cout << std::numeric_limits<float>::max() << std::endl;
//	std::cout << std::numeric_limits<float>::min() << std::endl;
//	std::cout << std::numeric_limits<double>::max() << std::endl;
//	std::cout << std::numeric_limits<double>::min() << std::endl;
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
