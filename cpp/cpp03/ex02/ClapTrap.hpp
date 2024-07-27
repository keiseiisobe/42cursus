#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;
	public:
		ClapTrap();
		ClapTrap(const std::string usner_name);
		ClapTrap(const ClapTrap& c);
		ClapTrap&	operator=(const ClapTrap&);
		~ClapTrap();
		std::string	get_name() const;
		int			get_hit_points() const;
		int			get_energy_points() const;
		int			get_attack_damage() const;
		void		set_name(std::string new_name);
		void		set_hit_points(int new_hit_points);
		void		set_energy_points(int new_energy_points);
		void		set_attack_damage(int new_attack_damage);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
