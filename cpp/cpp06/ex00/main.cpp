#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	/*
	std::cout<< "char_min: " << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
	std::cout << "char_max: " << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
	std::cout<< "int_min: " << std::fixed << std::setprecision(1) << std::numeric_limits<int>::min() << std::endl;
	std::cout << "int_max: " << std::fixed << std::setprecision(1) << std::numeric_limits<int>::max() << std::endl;
	std::cout << "float_min: " << std::fixed << std::setprecision(1) << std::numeric_limits<float>::min() << std::endl;
	std::cout << "float_max: " << std::fixed << std::setprecision(1) << std::numeric_limits<float>::max() << std::endl;
	std::cout << "double_min: " << std::fixed << std::setprecision(1) << std::numeric_limits<double>::min() << std::endl;
	std::cout << "double_max: " << std::fixed << std::setprecision(1) << std::numeric_limits<double>::max() << std::endl;
	*/
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
