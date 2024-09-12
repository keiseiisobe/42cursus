#include "MutantStack.hpp"
#include "color.hpp"
#include <iostream>
#include <vector>
#include <list>

int	passed_test = 0;
int	num_test = 0;

void	copyConstructorTest()
{
	std::cout << "test1.1: ";
	num_test++;
	MutantStack<float>	ms;
	for (int i = 0;i < 20;i++)
		ms.push(i);
	MutantStack<float>	copy(ms); // copy constructor
	if (ms.size() != copy.size())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong size" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << "test1.2: ";
	num_test++;
	MutantStack<float>::iterator	ms_it = ms.begin();
	MutantStack<float>::iterator	copy_it = copy.begin();
	for (;ms_it != ms.end();ms_it++,copy_it++)
	{
		if (*ms_it != *copy_it)
			break;
	}
	if (ms_it != ms.end())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong value at index " << ms_it - ms.begin() << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
}

void	copyAssignmentTest()
{
	std::cout << "test2.1: ";
	num_test++;
	MutantStack<double>	ms;
	for (int i = 0;i < 50;i++)
		ms.push(i);
	MutantStack<double>	copy;
	copy = ms; // copy assignment
	if (ms.size() != copy.size())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong size" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << "test2.2: ";
	num_test++;
	MutantStack<double>::iterator	ms_it = ms.begin();
	MutantStack<double>::iterator	copy_it = copy.begin();
	for (;ms_it != ms.end();ms_it++,copy_it++)
	{
		if (*ms_it != *copy_it)
			break;
	}
	if (ms_it != ms.end())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong value at index " << ms_it - ms.begin() << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
}

void	constructorsTest()
{
	std::cout << "********** Constructors Test **********" << std::endl;
	copyConstructorTest();
	copyAssignmentTest();
}

void	beginEndTest()
{
	std::cout << "********** begin() and end() Test **********" << std::endl;
	std::cout << "test3.1: ";
	num_test++;
	MutantStack<int>	ms;
	std::list<int>	ls;
	for (int i = 0;i < 5;i++)
	{
		ms.push(i);
		ls.push_back(i);
	}
	for (int i = 0;i < 2;i++)
	{
		ms.pop();
		ls.pop_back();
	}
	if (ms.size() != ls.size())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong size" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << "test3.2: ";
	num_test++;
	MutantStack<int>::iterator	ms_it = ms.begin();
	std::list<int>::iterator	ls_it = ls.begin();
	for (;ms_it != ms.end();ms_it++,ls_it++)
	{
		if (*ms_it != *ls_it)
			break;
	}
	if (ms_it != ms.end())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong value at index " << ms_it - ms.begin() << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
}

void	rbeginRendTest()
{
	std::cout << "********** rbegin() and rend() Test **********" << std::endl;
	std::cout << "test4.1: ";
	num_test++;
	MutantStack<int>	ms;
	std::vector<int>	vc;
	for (int i = 0;i < 100;i++)
	{
		ms.push(i);
		vc.push_back(i);
	}
	for (int i = 0;i < 50;i++)
	{
		ms.pop();
		vc.pop_back();
	}
	if (ms.size() != vc.size())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong size" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << "test4.2: ";
	num_test++;
	MutantStack<int>::reverse_iterator	ms_it = ms.rbegin();
	std::vector<int>::reverse_iterator	vc_it = vc.rbegin();
	for (;ms_it != ms.rend();ms_it++,vc_it++)
	{
		if (*ms_it != *vc_it)
			break;
	}
	if (ms_it != ms.rend())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: wrong value at index " << ms_it - ms.rbegin() << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
}

void	otherFunctionsTest()
{
	std::cout << "********** Other functions Test **********" << std::endl;
	std::cout << "test5.1: ";
	num_test++;
	MutantStack<int>	ms;
	if (!ms.empty())
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: empty() doesn't work" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
	std::cout << "test5.2: ";
	num_test++;
	ms.push(1);
	ms.push(2);
	if (ms.top() != 2)
	{
		std::cerr << color::red << "KO" << color::reset << std::endl;
		std::cerr << "Error: top() doesn't work" << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << std::endl;
	}
	else
	{
		std::cout << color::green << "OK" << color::reset << std::endl;
		passed_test++;
	}
}

int	main()
{
	constructorsTest();
	beginEndTest();
	rbeginRendTest();
	otherFunctionsTest();
	std::cout << std::endl << std::endl << "[ Test Finished ]" << std::endl;
	if (passed_test == num_test)
		std::cout << color::green << "OK [ " << passed_test << " / " << num_test << " ]" << color::reset << std::endl;
	else
		std::cerr << color::red << "KO [ " << passed_test << " / " << num_test << " ]" << color::reset << std::endl;
}
