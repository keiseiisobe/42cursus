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
	int	rand_num = rand() / RAND_MAX * 10;
	if (rand_num >= 0 && rand_num <= 3)
	{
		std::cout << "returned A type" << std::endl;
		return new A();
	}
	else if (rand_num >= 4 && rand_num <= 6)
	{
		std::cout << "returned B type" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "returned C type" << std::endl;
		return new C();
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C type" << std::endl;
	else
		std::cout << "Doesn't match any types" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A type" << std::endl;
		return;
	}
	catch (std::exception&)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B type" << std::endl;
		return;
	}
	catch (std::exception&)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C type" << std::endl;
		return;
	}
	catch (std::exception&)
	{
		std::cout << "Doesn't match any types" << std::endl;
	}
}
