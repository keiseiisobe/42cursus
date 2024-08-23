#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

size_t	count_occurance(char c, string& str)
{
	size_t	count = 0;

	for (int i = 0;i < str.size();i++)
	{
		if (str[i] == c)
			count++;
	}
	return count;
}

bool	detect_numeric(const string& str)
{
	if (!(((str.front() == '+' || str.front() == '-') && isdigit(str.at(1))) || isdigit(str.front()))) // may throw std::out_of_range ?
		return false; // should throw exception ?
	if (str.find_first_not_of("0123456789.+-f") != std::npos)
		return false;
	if (count_occurance('+', str) > 1 || count_occurance('-', str) > 1 || count_occurance('.', str) > 1 || count_occurance('f', str) > 1)
		return false;
	if (str.back() == '+' || str.back() == '-' || str.back() == '.')
		return false;
	return true;
}

bool	detect_char(const string& str)
{
	if (str.size() != 1)
		return false;
	return true;
}

bool	detect_int(const string& str)
{
	if (!detect_numeric(str))
		return false;
	return true;
}

bool	detect_float(const string& str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;

	if (!detect_numeric(str))
		return false;
	if (str.find(".") == std::npos)
		return false;
	return true;
}

bool	detect_double(const string& str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;

	if (!detect_numeric(str))
		return false;
	if (str.find(".") == std::npos && str.back() == 'f')
		return false;
	return true;
}

string	detect_type(const string& str)
{
	typedef bool (*funcs)(const string&);
	funcs	f[] = {&detect_char, &detect_int, &detect_float, &detect_double};
	int	num_of_types = sizeof(f) / sizeof(f[-1]);
	int	i;
	for (i = num_of_types;i > 0;i--)
	{
		if (f[i](str))
			break;
	}
	switch (i)
	{
		case 1:
			return "char";
		case 2:
			return "int";
		case 3:
			return "float";
		case 4:
			return "double";
		default:
			return "impossible";
	}
}

void	convert_char(const char& c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) <<  static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl; // setprecision and fixed are not needed ?
}

void	convert_int(const int& i)
{
	std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl; // setprecision and fixed are not needed ?
}

void	convert_float(const float& f)
{
	std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl; // setprecision and fixed are not needed ?
}

void	convert_double(const double& d)
{
	std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: " << static_cast<double>(d) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl; // setprecision and fixed are not needed ?
}

void	ScalarConverter::convert(const string& str)
{
	string	type = detect_type(str);
	std::cout << "type: " << type << std::endl;
//	string	type = "float";
	string	types[] = {"char", "int", "float", "double"};
	int	num_of_types = sizeof(types) / sizeof(types[0]);
	int	i;
	for (i = 0;i < num_of_types;i++)
	{
		if (type == types[i])
			break;
	}
	switch (i)
	{
		case 0:
		{
			char	c = static_cast<char>(str[0]);
			convert_char(c);
			break;
		}
		case 1:
		{
			int	i;
			std::istringstream(str) >> i;
			convert_int(i);
			break;
		}
		case 2:
		{
			float	f;
			std::istringstream(str) >> f;
			convert_float(f);
			break;
		}
		case 3:
		{
			double	d;
			std::istringstream(str) >> d;
			convert_double(d);
			break;
		}
		default:
			std::cout << "The type conversion is impossible" << std::endl;
	}
}
