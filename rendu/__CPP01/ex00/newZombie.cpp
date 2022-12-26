#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *newZombie(0);

	newZombie = new Zombie(name);
	
	return (newZombie);
}
