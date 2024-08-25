#pragma once

#include <iostream>
#include <iomanip>
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
