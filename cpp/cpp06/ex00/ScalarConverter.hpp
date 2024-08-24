#pragma once

#include <iostream>
#include <ios>
#include <iomanip>
#include <cctype>

#include <sstream>
#include <limits>
#include <climits>
#include <cfloat>
#include <cmath>

using std::string;

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter&	operator=(const ScalarConverter&);
		~ScalarConverter();
	public:
		static void	convert(const string& str);
};

class	NotNumeric : public std::exception {};
