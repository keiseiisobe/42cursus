#include "FragTrap.hpp"

void	print_all_attribute(FragTrap &f)
{
	std::cout << "-----FragTrap \"" << f.get_name() << "\"-----" << std::endl;
	std::cout << "hit points: " << f.get_hit_points() << std::endl;
	std::cout << "energy points: " << f.get_energy_points() << std::endl;
	std::cout << "attack damage: " << f.get_attack_damage() << std::endl;
	std::cout << "-------------------------" << std::endl;
}

int	main()
{
	FragTrap	p1("kisobe");

	print_all_attribute(p1);
	p1.attack("kmotoyama");
	print_all_attribute(p1);
	p1.takeDamage(2);
	print_all_attribute(p1);
	p1.beRepaired(3);
	print_all_attribute(p1);
	p1.highFivesGuys();
	print_all_attribute(p1);

	FragTrap	p2;

	print_all_attribute(p2);
	p2.attack("mkaihori");
	print_all_attribute(p2);
	p2.takeDamage(2);
	print_all_attribute(p2);
	p2.beRepaired(3);
	print_all_attribute(p2);
	p1.highFivesGuys();
	print_all_attribute(p2);

	FragTrap	p3(p1);

	print_all_attribute(p3);
	p3.attack("jyasukawa");
	print_all_attribute(p3);
	p3.takeDamage(101);
	print_all_attribute(p3);
	p3.beRepaired(3);
	print_all_attribute(p3);
	p1.highFivesGuys();
	print_all_attribute(p3);
	return 0;
}
