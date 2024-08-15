#pragma once

#include <iostream>
#include <cctype>

using std::string;

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter&	operator=(const ScalarConverter&);
		~ScalarConverter();
	public:
		static void	convert(string str);
};
