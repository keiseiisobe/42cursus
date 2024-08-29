#include "Array.hpp"
#include <iostream>

using std::string;

int	main()
{
	try
	{
		{
			std::cout << "***** Test1: default constructor *****" << std::endl << std::endl;
			Array<int>	a;
			// initialization test
			if (a.size() != 1 || a[0] != 0)
				throw std::string("Failed at Test1 because of bad initialization");
			// subscript operator test
			try
			{
				std::cout << a[1] << std::endl;
				throw std::string("Failed at Test1 because of bad subscript operator");
			}
			catch (std::exception&)
			{
			}
			try
			{
				a[1] = 1;
				throw std::string("Failed at Test1 because of bad subscript operator");
			}
			catch (std::exception&)
			{
			}
			std::cout << "passed Test1 !!!" << std::endl;
		}
		{
			std::cout << "***** Test2: constructor with parameter *****" << std::endl << std::endl;
			unsigned int	n = 10;
			Array<string>	a(n);
			if (a.size() != n)
				throw std::string("Failed at Test1 because of bad initialization");
			for (int i = 0;i < n;i++)
			{
				if (a[i] != 0)
					throw std::string("Failed at Test1 because of bad initialization");
			}
			try
			{
				std::cout << a[1] << std::endl;
				throw std::string("Failed at Test1 because of bad subscript operator");
			}
			catch (std::exception&)
			{
			}
			try
			{
				a[1] = 1;
				throw std::string("Failed at Test1 because of bad subscript operator");
			}
			catch (std::exception&)
			{
			}
			std::cout << "passed Test1 !!!" << std::endl;
		}
	}
	catch (std::string& msg)
	{
		std::cout << msg << std::endl;
	}
}

#include "Array.cpp"
