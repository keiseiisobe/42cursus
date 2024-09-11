#include <vector>
#include <list>
#include "easyfind.hpp"
#include "color.hpp"

struct Incrementor
{
	int	current;
	Incrementor(int start) : current(start) {};
	int	operator()(){return current++;}
};

void	foundVectorTest()
{
	std::cout << "----- found vector test -----" << std::endl;
	std::vector<int>	v1(10);
	struct Incrementor	incrementor(0);
	std::generate(v1.begin(), v1.end(), incrementor);
	std::cout << "created vector: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << std::endl;
	for (int i = 0;i < 10;i++)
	{
		std::cout << "test1." << i << ": ";
		std::vector<int>::iterator	result = easyfind(v1, i);
		if (result - v1.begin() != i)
		{
			std::cout << color::red << "KO" << color::reset << std::endl;
			std::cout << "    index: " << i << std::endl;
		}
		else
			std::cout << color::green << "OK" << color::reset << std::endl;
	}
}

void	foundListTest()
{
	std::cout << "----- found list test -----" << std::endl;
	std::list<int>	l1(10);
	struct Incrementor	incrementor(0);
	std::generate(l1.begin(), l1.end(), incrementor);
	std::cout << "created list: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << std::endl;
	for (int i = 0;i < 10;i++)
	{
		std::cout << "test2." << i << ": ";
		std::list<int>::iterator	result = easyfind(l1, i);
		int	index = 0;
		for (;result != l1.end();result++)
			index++;
		index = l1.size() - index;
		if (index != i)
		{
			std::cout << color::red << "KO" << color::reset << std::endl;
			std::cout << "    index: " << i << std::endl;
		}
		else
			std::cout << color::green << "OK" << color::reset << std::endl;
	}
}

void	notFoundVectorTest()
{
	std::cout << "----- not found vector test -----" << std::endl;
	std::vector<int>	v1(10);
	struct Incrementor	incrementor(0);
	std::generate(v1.begin(), v1.end(), incrementor);
	std::cout << "created vector: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << std::endl;
	{
		std::cout << "test3.1" << ": ";
		int	value = -1;
		std::vector<int>::iterator	result = easyfind(v1, value);
		if (result == v1.end())
			std::cout << color::green << "OK" << color::reset << std::endl;
		else
		{
			std::cout << color::red << "KO" << color::reset << std::endl;
			std::cout << "    value " << value << " was found somewhere" << std::endl;
		}
	}
	{
		std::cout << "test3.2" << ": ";
		int	value = 10;
		std::vector<int>::iterator	result = easyfind(v1, value);
		if (result == v1.end())
			std::cout << color::green << "OK" << color::reset << std::endl;
		else
		{
			std::cout << color::red << "KO" << color::reset << std::endl;
			std::cout << "    value " << value << " was found somewhere" << std::endl;
		}
	}
}

void	notFoundListTest()
{
	std::cout << "----- not found list test -----" << std::endl;
	std::list<int>	v1(10);
	struct Incrementor	incrementor(0);
	std::generate(v1.begin(), v1.end(), incrementor);
	std::cout << "created list: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << std::endl;
	{
		std::cout << "test4.1" << ": ";
		int	value = -1;
		std::list<int>::iterator	result = easyfind(v1, value);
		if (result == v1.end())
			std::cout << color::green << "OK" << color::reset << std::endl;
		else
		{
			std::cout << color::red << "KO" << color::reset << std::endl;
			std::cout << "    value " << value << " was found somewhere" << std::endl;
		}
	}
	{
		std::cout << "test4.2" << ": ";
		int	value = 10;
		std::list<int>::iterator	result = easyfind(v1, value);
		if (result == v1.end())
			std::cout << color::green << "OK" << color::reset << std::endl;
		else
		{
			std::cout << color::red << "KO" << color::reset << std::endl;
			std::cout << "    value " << value << " was found somewhere" << std::endl;
		}
	}
}

void	foundTest()
{
	std::cout << "********** found test **********" << std::endl;
	foundVectorTest();
	foundListTest();
}

void	notFoundTest()
{
	std::cout << "********** not found test **********" << std::endl;
	notFoundVectorTest();
	notFoundListTest();
}

int	main()
{
	foundTest();
	std::cout << std::endl;
	notFoundTest();
}
