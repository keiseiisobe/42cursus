#include "Weapon.hpp"

Weapon::Weapon(std::string init_type)
{
	type = init_type;
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}
