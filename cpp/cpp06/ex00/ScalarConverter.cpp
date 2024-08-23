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

size_t	count_occurance(const char c, const string& str)
{
	size_t	count = 0;

	for (size_t i = 0;i < str.size();i++)
	{
		if (str[i] == c)
			count++;
	}
	return count;
}

bool	detect_numeric(const string& str)
{
	if (!(((str[0] == '+' || str[0] == '-') && isdigit(str.at(1))) || isdigit(str[0])))
		return false;
	if (str.find_first_not_of("0123456789.+-f") != string::npos)
		return false;
	if (count_occurance('+', str) > 1 || count_occurance('-', str) > 1 || count_occurance('.', str) > 1 || count_occurance('f', str) > 1)
		return false;
	if (str[str.size() - 1] == '+' || str[str.size() - 1] == '-' || str[str.size() - 1] == '.')
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
	if (str.find(".") == string::npos)
		return false;
	return true;
}

bool	detect_double(const string& str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;

	if (!detect_numeric(str))
		return false;
	if (str.find(".") == string::npos || str[str.size() - 1] == 'f')
		return false;
	return true;
}

string	detect_type(const string& str)
{
	typedef bool (*funcs)(const string&);
	funcs	f[] = {&detect_char, &detect_int, &detect_float, &detect_double};
	int	num_of_types = sizeof(f) / sizeof(f[-1]);
	int	i;
	for (i = num_of_types - 1;i >= 0;i--)
	{
		if (f[i](str))
			break;
	}
	switch (i)
	{
		case 0:
			return "char";
		case 1:
			return "int";
		case 2:
			return "float";
		case 3:
			return "double";
		default:
			return "impossible";
	}
}

void	convert_char(const char& c)
{
	//char
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//int
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	//float
	std::cout << "float: " << std::fixed << std::setprecision(1) <<  static_cast<float>(c) << "f" << std::endl;
	//double
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	convert_int(const int& i)
{
	//char
	if (i >= CHAR_MIN && i <= CHAR_MAX)
	{
		if (isprint(static_cast<char>(i)))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	//int
	std::cout << "int: " << i << std::endl;
	//float
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	//double
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void	convert_float(const float& f)
{
	//char
	if (f >= CHAR_MIN && f <= CHAR_MAX)
	{
		if (isprint(static_cast<char>(f)))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	//int
	if (f >= INT_MIN && f <= INT_MAX)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	//float
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	//double
	if (std::isnan(f) || std::isinf(f))
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void	convert_double(const double& d)
{
	//char
	if (d >= CHAR_MIN && d <= CHAR_MAX)
	{
		if (isprint(static_cast<char>(d)))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	//int
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	//float
	if (d >= FLT_MIN && d <= FLT_MAX)
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else if (std::isnan(d) || std::isinf(d))
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	//double
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::convert(const string& str)
{
	string	type = detect_type(str);
	std::cout << "detected type: " << type << std::endl;
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
			if (str == "nanf")
				f = std::numeric_limits<float>::quiet_NaN();
			else if (str == "+inff")
				f = std::numeric_limits<float>::infinity();
			else if (str == "-inff")
				f = -1 * std::numeric_limits<float>::infinity();
			else
				std::istringstream(str) >> f;
			convert_float(f);
			break;
		}
		case 3:
		{
			double	d;
			if (str == "nan")
				d = std::numeric_limits<double>::quiet_NaN();
			else if (str == "+inf")
				d = std::numeric_limits<double>::infinity();
			else if (str == "-inf")
				d = -1 * std::numeric_limits<double>::infinity();
			else
				std::istringstream(str) >> d;
			convert_double(d);
			break;
		}
		default:
			std::cout << "The type conversion is impossible" << std::endl;
	}
}
