#include "ZombieFactory.h"


ZombieFactory::ZombieFactory(int newHealth, int newDamage, sf::RenderWindow& window) : window(window)
{
	health = newHealth;
	damage = newDamage;
}

int ZombieFactory::getHealth() const
{
	return health;
}

int ZombieFactory::getDamage() const
{
	return damage;
}

void ZombieFactory::setHealth(int newHealth)
{
	health = newHealth;
}

void ZombieFactory::setDamage(int newDamage)
{
	damage = newDamage;
}
