#include "Zombie.h"

// This class does basically nothing!

Zombie::Zombie() : ZombieFactory(0, 0, window)
{

}

Zombie::Zombie(int newHealth, int newDamage, sf::RenderWindow& window) : ZombieFactory(newHealth, newDamage, window)
{

}

void Zombie::setPosition(float x, float y)
{
	
}

sf::Vector2f Zombie::getPosition() const
{
	return sf::Vector2f(1000000, 1000000);
}

void Zombie::draw()
{

}

void Zombie::Move()
{
	
}