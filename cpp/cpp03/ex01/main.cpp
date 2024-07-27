#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	p1("keisei");
	ScavTrap	p2;
	p2 = p1;
//	ScavTrap	p2(p1);

	std::cout << "p1: name: " << p1.get_name() << std::endl;
	std::cout << "p1: hit: " << p1.get_hit_points() << std::endl;
	std::cout << "p1: energy: " << p1.get_energy_points() << std::endl;
	std::cout << "p1: damage: " << p1.get_attack_damage() << std::endl;

	std::cout << "p2: name: " << p2.get_name() << std::endl;
	std::cout << "p2: hit: " << p2.get_hit_points() << std::endl;
	std::cout << "p2: energy: " << p2.get_energy_points() << std::endl;
	std::cout << "p2: damage: " << p2.get_attack_damage() << std::endl;

	p1.attack("motoyama");
	p1.takeDamage(2);
	p1.beRepaired(3);
	p1.guardGate();
	p2.attack("motoyama");
	p2.takeDamage(2);
	p2.beRepaired(3);
	p2.guardGate();
//	p3.attack("motoyama");
//	p3.takeDamage(2);
//	p3.beRepaired(3);
}
