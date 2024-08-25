#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base*	generate(void)
{
	srand(time(NULL));
	int	rand_num = int((double(rand()) / RAND_MAX) * 10);
	if (rand_num >= 0 && rand_num <= 3)
	{
		std::cout << "A type was Instanciated:" << std::endl;
		return new A();
	}
	else if (rand_num >= 4 && rand_num <= 6)
	{
		std::cout << "B type was Instanciated:" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "C type was Instanciated:" << std::endl;
		return new C();
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A type detected by pointer dynamic_cast" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B type detected by pointer dynamic_cast" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C type detected by pointer dynamic_cast" << std::endl;
	else
		std::cout << "Doesn't match any types" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A type detected by reference dynamic_cast" << std::endl;
		return;
	}
	catch (std::exception&)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B type detected by reference dynamic_cast" << std::endl;
		return;
	}
	catch (std::exception&)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C type detected by reference dynamic_cast" << std::endl;
		return;
	}
	catch (std::exception&)
	{
		std::cout << "Doesn't match any types" << std::endl;
	}
}
