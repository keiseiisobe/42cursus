#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*funcs)(void);
	funcs	f[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	const int	l_size = sizeof(funcs)/sizeof(funcs[0]);
	int			i;

	for (i = 0;i < l_size;i++)
	{
		if (level == levels[i])
			break;
	}
	switch (i)
	{
		case 0:
			f[i]();
			break;
		case 1:
			f[i]();
			break;
		case 2:
			f[i]();
			break;
		case 3:
			f[i]();
			break;
		default:
			std::cout << "It's not Harl !!!" << std::endl;
			break;
	}
}
