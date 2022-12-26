#include "HumanB.hpp"

HumanB::HumanB(void)
{
	return ;
}

HumanB::HumanB(std::string name) : __name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon &weapon_type)
{
	this->__weapon_type = &weapon_type;
}

void	HumanB::attack(void)
{
	if (!this->__weapon_type)
	{
		std::cout << "Did you try to hit me with no weapon ? AHAHAHAHA" << std::endl;
		return ;
	}
	std::cout << this->__name << " Attack with they're : " << this->__weapon_type->getType() << std::endl;
}