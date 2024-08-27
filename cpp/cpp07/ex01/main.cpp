#include "iter.hpp"
#include <iostream>
#include <sstream>

using std::string;
std::stringstream	output;

template<class T>
void	print_with_semicolon(T t)
{
	output << t << ";";
}

template<class T>
void	print_after_adding_5(T t)
{
	output << t + 5 << " ";
}

int	main()
{
	size_t	size = 5;
	{
		std::cout << "********** Test1.1: print with semicolon (type: string) **********" << std::endl << std::endl;
		string	names[size] = {"kisobe", "hoyuki", "kojwatan", "kmotoyama", "mkaihori"};
		iter(names, size, &print_with_semicolon);
		string	expected_output;
		for (size_t i = 0;i < size;i++)
		{
			expected_output += names[i] + ";";
		}
		std::cout << "expected output is ..." << std::endl << expected_output << std::endl << std::endl;
		std::cout << "your output is ..." << std::endl << output.str() << std::endl << std::endl;
		if (output.str() != expected_output)
			std::cout << "output is wrong T_T" << std::endl;
		else
			std::cout << "output is correct ^_^" << std::endl << std::endl;
	}
	output.str("");
	{
		std::cout << "********** Test1.2: print with semicolon (type: float) **********" << std::endl << std::endl;
		float	nums[size] = {2.0, 4.0, 6.0, 8.0, 10.0};
		iter(nums, size, &print_with_semicolon);
		string	expected_output;
		for (size_t i = 0;i < size;i++)
		{
			std::stringstream	ss;
			ss << nums[i];
			expected_output += ss.str() + ";";
		}
		std::cout << "expected output is ..." << std::endl << expected_output << std::endl << std::endl;
		std::cout << "your output is ..." << std::endl << output.str() << std::endl << std::endl;
		if (output.str() != expected_output)
			std::cout << "output is wrong T_T" << std::endl;
		else
			std::cout << "output is correct ^_^" << std::endl << std::endl;
	}
	output.str("");
	{
		std::cout << "********** Test2.1: print after adding 5 (type: int) **********" << std::endl << std::endl;
		int	nums[size] = {1, 2, 3, 4, 5};
		iter(nums, size, &print_after_adding_5);
		string	expected_output;
		for (size_t i = 0;i < size;i++)
		{
			std::stringstream	ss;
			ss << (nums[i] + 5);
			expected_output += ss.str() + " ";
		}
		std::cout << "expected output is ..." << std::endl << expected_output << std::endl << std::endl;
		std::cout << "your output is ..." << std::endl << output.str() << std::endl << std::endl;
		if (output.str() != expected_output)
			std::cout << "output is wrong T_T" << std::endl;
		else
			std::cout << "output is correct ^_^" << std::endl << std::endl;
	}
	output.str("");
	{
		std::cout << "********** Test2.2: print after adding 5 (type: double) **********" << std::endl << std::endl;
		double	nums[size] = {111.1, 222.2, 333.3, 444.4, 555.5};
		iter(nums, size, &print_after_adding_5);
		string	expected_output;
		for (size_t i = 0;i < size;i++)
		{
			std::stringstream	ss;
			ss << (nums[i] + 5);
			expected_output += ss.str() + " ";
		}
		std::cout << "expected output is ..." << std::endl << expected_output << std::endl << std::endl;
		std::cout << "your output is ..." << std::endl << output.str() << std::endl << std::endl;
		if (output.str() != expected_output)
			std::cout << "output is wrong T_T" << std::endl;
		else
			std::cout << "output is correct ^_^" << std::endl << std::endl;
	}
}
