#include "Plant.h"

Plant::Plant() : PlantFactory(0, 0, 0, window)
{

}


Plant::Plant(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : PlantFactory(newCost, newHealth, newAttackDamage, window)
{
	
}

sf::Vector2f Plant::getPosition() const
{
	// do nothing
	return sf::Vector2f(1000000, 1000000);
}


void Plant::draw()
{
	// nothing to draw here
}

void Plant::setPosition(float x, float y)
{
	// nothing to set here
}