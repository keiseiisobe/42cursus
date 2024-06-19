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
	std::cout << "I love this fresh air." << std::endl;
	std::cout << "I just want to come at school by my bicyle!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I can't believe it's too hot in May." << std::endl;
	std::cout << "I can't expect it will in July." << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "What the hell this weather!" << std::endl;
	std::cout << "It has been heavy rainy and too hot for one week!" << std::endl;
	std::cout << "I don't feel like studying for one week!" << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Goddam." << std::endl;
	std::cout << "I am gonna ask god why you don't have such enough power to keep weather comfortable." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void	(Harl::*funcs)(void);
	funcs			f[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	const int		l_size = sizeof(levels) / sizeof(levels[0]);
	int				i;

	for (i = 0;i < l_size;i++)
	{
		if (level == levels[i])
			break;
	}
	if (i != l_size)
		(this->*f[i])();
}
