#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name(""), hit_points(0), energy_points(0), attack_damage(0)
{
	std::cout << "ClapTrap default constructor launched." << std::endl;
}

ClapTrap::ClapTrap(const std::string user_name)
	: name(user_name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor launched." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
	: name(c.get_name()), hit_points(c.get_hit_points()), energy_points(c.get_energy_points()), attack_damage(c.get_attack_damage())
{
	std::cout << "ClapTrap copy constructor launched." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& c)
{
	std::cout << "ClapTrap copy assignment launched." << std::endl;
	name = c.get_name();
	hit_points = c.get_hit_points();
	energy_points = c.get_energy_points();
	attack_damage = c.get_attack_damage();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor launched." << std::endl;
}

std::string	ClapTrap::get_name() const
{
	return name;
}

int	ClapTrap::get_hit_points() const
{
	return hit_points;
}

int	ClapTrap::get_energy_points() const
{
	return energy_points;
}

int	ClapTrap::get_attack_damage() const
{
	return attack_damage;
}

void	ClapTrap::set_name(std::string new_name)
{
	name = new_name;
}

void	ClapTrap::set_hit_points(int new_hit_points)
{
	hit_points = new_hit_points;
}

void	ClapTrap::set_energy_points(int new_energy_points)
{
	energy_points = new_energy_points;
}

void	ClapTrap::set_attack_damage(int new_attack_damage)
{
	attack_damage = new_attack_damage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energy_points <= 0 || hit_points <= 0)
		std::cout << "ClapTrap " << name << " has no power to attack " << target << "." << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (energy_points <= 0 || hit_points <= 0)
		std::cout << "Stop! " << name << "is already dead." << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " was attacked, causing " << amount << " points of damage!" << std::endl;
		hit_points -= amount;
		if (hit_points < 0)
			hit_points = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points <= 0 || hit_points <= 0)
		std::cout << "ClapTrap " << name << " has no power even to eat an apple." << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " got an apple, so got " << amount << " hit points!" << std::endl;
		hit_points += amount;
		energy_points--;
	}
}
