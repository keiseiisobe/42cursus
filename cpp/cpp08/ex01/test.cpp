#include <iostream>
#include "Span.hpp"
#include "color.hpp"

int	passed_test = 0;
int	num_test = 0;

void	copyTest(const Span& copy, const Span& s, unsigned int N)
{
	static int	i = 1;
	{
		std::cout << "test1." << i++ << ": ";
		num_test++;
		if (copy.getN() != s.getN())
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: N_ variable doesn't match" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
		std::cout << "test1." << i++ << ": ";
		num_test++;
		unsigned int	i = 0;
		for (;i < N;i++)
		{
			if (s[i] != (int)i)
				break;
		}
		if (i != N)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: doesn't match at value_[" << i << "]" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
}

void	copyConstructorsTest()
{
	std::cout << "********** Copy Constructors Test **********" << std::endl;
	unsigned int	N = 10;
	Span	s(N);
	s.generateN(10, 0); // {0 ... 9}
	{
		Span	copy(s); // copy constructor
		copyTest(copy, s, N);
	}
	{
		Span	copy = s; // copy assignment
		copyTest(copy, s, N);
	}
}

void	addNumberTest()
{
	std::cout << "********** addNumber Test **********" << std::endl;
	std::cout << "test2.1: ";
	num_test++;
	unsigned int	N = 5;
	Span	s(N);
	int	nums[5] = {42, 24, 4, 2, 4422};
	for (int i = 0;i < 5;i++)
		s.addNumber(nums[i]);
	int i = 0;
	for (;i < 5;i++)
	{
		if (s[i] != nums[i])
			break;
	}
	if (i != 5)
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: doesn't match at value_[" << i << "]" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << "test2.2: ";
	num_test++;
	try
	{
		s.addNumber(2244);
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: exception aren't thrown" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	catch(std::string&)
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
}

void	shortestSpanTest()
{
	std::cout << "********** shortestSpan Test **********" << std::endl;
	{
		std::cout << "test3.1: ";
		num_test++;
		unsigned int	N = 5;
		Span	s(N);
		int	nums[5] = {110, 819, 356, 1000, 921};
		for (int i = 0;i < 5;i++)
			s.addNumber(nums[i]);
		if (s.shortestSpan() != 1000 - 921)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: shortestSpan failed" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
	{
		std::cout << "test3.2: ";
		num_test++;
		Span	s(0);
		try
		{
			s.shortestSpan();
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: exception aren't thrown" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		catch(std::string&)
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
	{
		std::cout << "test3.3: ";
		num_test++;
		Span	s(1);
		try
		{
			s.shortestSpan();
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: exception aren't thrown" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		catch(std::string&)
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
}

void	longestSpanTest()
{
	std::cout << "********** longestSpan Test **********" << std::endl;
	{
		std::cout << "test4.1: ";
		num_test++;
		unsigned int	N = 5;
		Span	s(N);
		int	nums[5] = {110, 819, 356, 1000, 921};
		for (int i = 0;i < 5;i++)
			s.addNumber(nums[i]);
		if (s.longestSpan() != 1000 - 110)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: longestSpan failed" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
	{
		std::cout << "test4.2: ";
		num_test++;
		Span	s(0);
		try
		{
			s.longestSpan();
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: exception aren't thrown" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		catch(std::string&)
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
	{
		std::cout << "test4.3: ";
		num_test++;
		Span	s(1);
		try
		{
			s.longestSpan();
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: exception aren't thrown" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		catch(std::string&)
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
}

void	largeNumberTest()
{
	std::cout << "********** Large Number Test **********" << std::endl;
	{
		std::cout << "test5.1: ";
		num_test++;
		unsigned int	N = 10000;
		Span	s(N);
		s.fillN(N, 42);
		unsigned int	i = 0;
		for (;i < N;i++)
		{
			if (s[i] != 42)
				break;
		}
		if (i != N)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: dosn't match at index " << i << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
		std::cout << "test5.2: ";
		num_test++;
		if (s.shortestSpan() != 0)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: shortestSpan failed" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
		std::cout << "test5.3: ";
		num_test++;
		if (s.longestSpan() != 0)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: longestSpan failed" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
	{
		std::cout << "test5.4: ";
		num_test++;
		unsigned int	N = 1000000;
		Span	s(N);
		s.generateN(N, 0);
		unsigned int	i = 0;
		for (;i < N;i++)
		{
			if (s[i] != (int)i)
				break;
		}
		if (i != N)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: dosn't match at index " << i << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
		std::cout << "test5.5: ";
		num_test++;
		if (s.shortestSpan() != 1)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: shortestSpan failed" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
		std::cout << "test5.6: ";
		num_test++;
		if (s.longestSpan() != 999999)
		{
			std::cerr << color::red << "KO" << color::reset << std::endl;
			std::cerr << "Error: longestSpan failed" << std::endl;
			std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
}

int	main()
{
	try
	{
		copyConstructorsTest();
		addNumberTest();
		shortestSpanTest();
		longestSpanTest();
		largeNumberTest();
		std::cout << std::endl << std::endl << "[ Test Finished ]" << std::endl;
		if (num_test == passed_test)
			std::cout << color::green << "OK [ " << passed_test << " / " << num_test << " ]" << color::reset << std::endl;
		else
			std::cout << color::red << "KO [ " << passed_test << " / " << num_test << " ]" << color::reset << std::endl;
	}
	catch(std::exception& e)
	{
		e.what();
	}
}
