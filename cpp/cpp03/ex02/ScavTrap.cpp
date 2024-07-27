#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << "ScavTrap default constructor launched." << std::endl;
}

ScavTrap::ScavTrap(const std::string user_name)
	: ClapTrap(user_name)
{
	std::cout << "ScavTrap constructor launched." << std::endl;
	set_hit_points(100);
	set_energy_points(50);
	set_attack_damage(20);
}

ScavTrap::ScavTrap(const ScavTrap& s)
	: ClapTrap(s)
{
	std::cout << "ScavTrap copy constructor launched." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& s)
{
	std::cout << "ScavTrap copy assignment launched." << std::endl;
	set_name(s.get_name());
	set_hit_points(s.get_hit_points());
	set_energy_points(s.get_energy_points());
	set_attack_damage(s.get_attack_damage());
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor launched." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (get_energy_points() <= 0 || get_hit_points() <= 0)
		std::cout << "ScavTrap " << get_name() << " has no power to attack " << target << "." << std::endl;
	else
	{
		std::cout << "ScavTrap " << get_name() << " attacks " << target << ", causing " << get_attack_damage() << " points of damage!" << std::endl;
		set_energy_points(get_energy_points() - 1);
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
