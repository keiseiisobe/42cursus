#include "Span.hpp"
#include "color.hpp"

int	passed_test = 0;
int	num_test = 0;

void	copyConstructorTest()
{
	std::cout << "---------- Copy constructor Test ----------" << std::endl;
	int	N = 10;
	Span	s(N);
	{
		std::cout << "test1.1: ";
		num_test++;
		s.generate(10, 5); // {0 ... 9}
		int	i = 0;
		for (;i < N;i++)
		{
			std::cout << i << std::endl;
			if (s[i] != i)
				break;
		}
		if (i != N)
		{
			std::cerr << color::red << "KO" << std::endl;
			std::cerr << "Error: copy constructor failed at value_[" << i << "]" << color::reset << std::endl;
			std::cerr << "comes from " << __FILE__ << ":" << __FUNCTION__ << "():line" << __LINE__ << std::endl;
		}
		else
		{
			std::cout << color::green << "OK" << color::reset << std::endl;
			passed_test++;
		}
	}
}

void	copyTest()
{
	std::cout << "********** Copy Test **********" << std::endl;
	copyConstructorTest();
}

int	main()
{
	copyTest();
}
