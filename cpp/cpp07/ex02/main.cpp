#include "Array.hpp"
#include <iostream>

int	main()
{
	// use template function

	try
	{
		{
			std::cout << "***** size == 1 *****"<< std::endl;
			Array<int>	a1;
			std::cout << "a1.size: " << a1.size() << std::endl;
			Array<int>	a2(a1);
			std::cout << "a2.size: " << a2.size() << std::endl;
			Array<int>	a3;
			a3 = a1;
			std::cout << "a3.size: " << a3.size() << std::endl;
		}

		std::cout << std::endl << "***** size != 1 *****"<< std::endl;
		Array<int>	a1(10);
		std::cout << "a1.size: " << a1.size() << std::endl;
		Array<int>	a2(a1);
		std::cout << "a2.size: " << a2.size() << std::endl;
		Array<int>	a3(15);
		a3 = a1;
		std::cout << "a3.size: " << a3.size() << std::endl;
	}
	catch (Array<int>::sizeMismatch& sm)
	{
		sm.what();
	}
}

#include "Array.cpp"
