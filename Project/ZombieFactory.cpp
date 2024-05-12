#include "ZombieFactory.h"


ZombieFactory::ZombieFactory(int newHealth, int newDamage, sf::RenderWindow& window) : currentFrame(0), frameWidth(150), frameHeight(150), frameCount(45), frameDuration(0.1f), window(window)
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
