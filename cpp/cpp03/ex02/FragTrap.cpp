#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	std::cout << "FragTrap default constructor launched." << std::endl;
}

FragTrap::FragTrap(const std::string user_name)
	: ClapTrap(user_name)
{
	std::cout << "FragTrap constructor launched." << std::endl;
	set_hit_points(100);
	set_energy_points(100);
	set_attack_damage(30);
}

FragTrap::FragTrap(const FragTrap& s)
	: ClapTrap(s)
{
	std::cout << "FragTrap copy constructor launched." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& s)
{
	std::cout << "FragTrap copy assignment launched." << std::endl;
	set_name(s.get_name());
	set_hit_points(s.get_hit_points());
	set_energy_points(s.get_energy_points());
	set_attack_damage(s.get_attack_damage());
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor launched." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap is requesting a positive high fives." << std::endl;
}
