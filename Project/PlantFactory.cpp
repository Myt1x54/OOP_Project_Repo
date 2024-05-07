#include "PlantFactory.h"


PlantFactory::PlantFactory(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : window(window)
{
	cost = newCost;
	health = newHealth;
	attackDamage = newAttackDamage;
}



void PlantFactory::setCost(int newCost)
{
	cost = newCost;
}
void PlantFactory::setHealth(int newHealth)
{
	health = newHealth;
}
void PlantFactory::setAttackDamage(int newAttackDamage)
{
	attackDamage = newAttackDamage;
}

int PlantFactory::getCost() const
{
	return cost;
}
int PlantFactory::getHealth() const
{
	return health;
}
int PlantFactory::getAttackDamage() const
{
	return attackDamage;
}