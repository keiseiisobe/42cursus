#include "Base.hpp"
#include <unistd.h>

int	main()
{
	for (int i = 0;i < 10;i++)
	{
		Base	*b = generate();
		identify(b);
		identify(*b);
		delete b;
		std::cout << std::endl;
		sleep(1);
	}
}
