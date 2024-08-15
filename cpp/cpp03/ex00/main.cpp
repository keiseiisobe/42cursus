#include "ClapTrap.hpp"

void	print_all_attribute(ClapTrap &c)
{
	std::cout << "-----ClapTrap \"" << c.get_name() << "\"-----" << std::endl;
	std::cout << "hit points: " << c.get_hit_points() << std::endl;
	std::cout << "energy points: " << c.get_energy_points() << std::endl;
	std::cout << "attack damage: " << c.get_attack_damage() << std::endl;
	std::cout << "-------------------------" << std::endl;
}

int	main()
{
	ClapTrap	p1("kisobe");

	print_all_attribute(p1);
	p1.attack("kmotoyama");
	print_all_attribute(p1);
	p1.takeDamage(2);
	print_all_attribute(p1);
	p1.beRepaired(3);
	print_all_attribute(p1);

	ClapTrap	p2;

	print_all_attribute(p2);
	p2.attack("mkaihori");
	print_all_attribute(p2);
	p2.takeDamage(2);
	print_all_attribute(p2);
	p2.beRepaired(3);
	print_all_attribute(p2);

	ClapTrap	p3(p1);

	print_all_attribute(p3);
	p3.attack("jyasukawa");
	print_all_attribute(p3);
	p3.takeDamage(11);
	print_all_attribute(p3);
	p3.beRepaired(3);
	print_all_attribute(p3);
}
