#include "MutantStack.hpp"
#include "color.hpp"
#include <iostream>
#include <list>

int	passed_test = 0;
int	num_test = 0;

int	main()
{
	std::cout << "********** Compare to List Test **********" << std::endl;
	std::cout << "test1.1: ";
	num_test++;
	MutantStack<int>	ms;
	std::list<int>	ls;
	for (int i = 0;i < 5;i++)
	{
		ms.push(i);
		ls.push_back(i);
	}
	if (ms.size() != ls.size())
		std::cerr << color::red << "KO" << color::reset << std::endl;
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << "test1.2: ";
	num_test++;
	MutantStack<int>::iterator	ms_it = ms.begin();
	std::list<int>::iterator	ls_it = ls.begin();
	for (;ms_it != ms.end();ms_it++,ls_it++)
	{
		if (*ms_it != *ls_it)
			break;
	}
	if (ms_it != ms.end())
		std::cerr << color::red << "KO" << color::reset << std::endl;
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << std::endl << std::endl << "[ Test Finished ]" << std::endl;
	if (passed_test == num_test)
		std::cout << color::green << "OK [ " << passed_test << " / " << num_test << " ]" << color::reset << std::endl;
	else
		std::cerr << color::red << "KO [ " << passed_test << " / " << num_test << " ]" << color::reset << std::endl;
}
