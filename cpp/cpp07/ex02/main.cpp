#include "Array.hpp"
#include <iostream>

int	main()
{
	try
	{
		{
			std::cout << "***** Test1: default constructor *****" << std::endl << std::endl;
			Array<int>	a;
			// initialization test
			if (a.size() != 1 || a[0] != 0)
				throw std::string("Failed at Test1.1");
			// subscript operator test
			try
			{
				std::cout << a[1] << std::endl;
				throw std::string("Failed at Test1.2");
			}
			catch (std::exception&)
			{
			}
			try
			{
				a[1] = 1;
				throw std::string("Failed at Test1.3");
			}
			catch (std::exception&)
			{
			}
			std::cout << "passed Test1 !!!" << std::endl;
		}
		{
			std::cout << "***** Test2: constructor with parameter *****" << std::endl << std::endl;
			unsigned int	n = 10;
			Array<float>	a(n);
			// initialization test
			if (a.size() != n)
				throw std::string("Failed at Test2.1");
			for (unsigned int i = 0;i < n;i++)
			{
				if (a[i] != static_cast<float>(0))
					throw std::string("Failed at Test2.2");
			}
			// subscript operator test
			for (unsigned int i = 0;i < n;i++)
			{
				a[i] = static_cast<float>(i);
			}
			for (unsigned int i = 0;i < n;i++)
			{
				if (a[i] != static_cast<float>(i))
					throw std::string("Failed at Test2.3");
			}
			try
			{
				std::cout << a[n + 1] << std::endl;
				throw std::string("Failed at Test2.4");
			}
			catch (std::exception&)
			{
			}
			try
			{
				a[n + 1] = 1;
				throw std::string("Failed at Test2.5");
			}
			catch (std::exception&)
			{
			}
			std::cout << "passed Test2 !!!" << std::endl;
		}
		{
			std::cout << "***** Test3: copy constructor *****" << std::endl << std::endl;
			unsigned int	n = 100;
			Array<double>	a(n);
			Array<double>	b(a); // copy constructor
			// initialization test
			if (b.size() != n)
				throw std::string("Failed at Test3.1");
			for (unsigned int i = 0;i < n;i++)
			{
				if (b[i] != 0)
					throw std::string("Failed at Test3.2");
			}
			// subscript operator test
			for (unsigned int i = 0;i < n;i++)
			{
				b[i] = static_cast<double>(i);
			}
			for (unsigned int i = 0;i < n;i++)
			{
				if (b[i] != static_cast<double>(i))
					throw std::string("Failed at Test3.3");
			}
			try
			{
				std::cout << b[n + 1] << std::endl;
				throw std::string("Failed at Test3.4");
			}
			catch (std::exception&)
			{
			}
			try
			{
				b[n + 1] = 1;
				throw std::string("Failed at Test3.5");
			}
			catch (std::exception&)
			{
			}
			// deep copy test
			for (unsigned int i = 0;i < n;i++)
			{
				if (a[i] != 0)
					throw std::string("Failed at Test3.6");
			}
			std::cout << "passed Test3 !!!" << std::endl;
		}
		{
			std::cout << "***** Test4: copy assignment *****" << std::endl << std::endl;
			unsigned int	n = 500;
			Array<char>	a(n);
			try
			{
				Array<char>	b;
				b = a; // copy assignment
				throw std::string("Failed at Test4.1");
			}
			catch (Array<char>::sizeMismatch& s)
			{
			}
			for (unsigned int i = 0;i < n;i++)
			{
				a[i] = 'a';
			}
			Array<char>	b(n);
			b = a; // copy assignment
			// assignment test
			if (b.size() != n)
				throw std::string("Failed at Test4.2");
			for (unsigned int i = 0;i < n;i++)
			{
				if (b[i] != 'a')
					throw std::string("Failed at Test4.3");
			}
			// subscript operator test
			try
			{
				std::cout << b[n + 1] << std::endl;
				throw std::string("Failed at Test4.4");
			}
			catch (std::exception&)
			{
			}
			try
			{
				b[n + 1] = 1;
				throw std::string("Failed at Test4.5");
			}
			catch (std::exception&)
			{
			}
			// deep copy test
			for (unsigned int i = 0;i < n;i++)
			{
				b[i] = 'f';
			}
			for (unsigned int i = 0;i < n;i++)
			{
				if (a[i] != 'a')
					throw std::string("Failed at Test4.6");
			}
			std::cout << "passed Test4 !!!" << std::endl;
		}
	}
	catch (std::string& msg)
	{
		std::cout << msg << std::endl;
	}
}

#include "Array.tpp"
