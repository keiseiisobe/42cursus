#include "Span.hpp"

int	main()
{
	try
	{
		Span	s(10);

		std::cout << "At start" << std::endl;
		std::cout << "size: " << s.getSize() << std::endl;
		std::cout << "capacity: " << s.getCapacity() << std::endl;

		std::cout << "Looping ..." << std::endl << std::endl;
		for (int i = 10;i > 0;i--)
		{
//			std::cout << std::endl;
			s.addNumber(i);
//			std::cout << "added " << i << std::endl;
//			std::cout << "size: " << s.getSize() << std::endl;
//			std::cout << "capacity: " << s.getCapacity() << std::endl;
		}
		std::cout << "before sort" << std::endl;
		for (int i = 0;i < 10;i++)
			std::cout << s[i] << std::endl;
		s.sort();
		std::cout << "after sort" << std::endl;
		for (int i = 0;i < 10;i++)
	 		std::cout << s[i] << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		e.what();
	}
}
