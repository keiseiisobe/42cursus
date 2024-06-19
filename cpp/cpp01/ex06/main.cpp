#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Notice: ./harlFilter [level]" << std::endl;
		return 1;
	}
	std::string	level = static_cast<std::string>(argv[1]);
	class Harl	h;

	h.complain(level);
	return 0;
}
