#include "ScalarConverter.hpp"

void	convert_string_to_char(string str)
{
	if (str.size() != 1)
		std::cout << "char: impossible" << std::endl;
	else if (std::iscntrl(str[0]))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << str.c_str()[0] << std::endl;
}

void	convert_string_to_int(str)
{

}

void	ScalarConverter::convert(string str)
{
	convert_string_to_char(str);
	convert_string_to_int(str);
	convert_string_to_float(str);
	convert_string_to_double(str);
}
