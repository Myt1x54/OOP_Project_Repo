#include "Plant.h"


Plant::Plant(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : window(window)
{
	cost = newCost;
	health = newHealth;
	attackDamage = newAttackDamage;
}

void Plant::setCost(int newCost)
{
	cost = newCost;
}
void Plant::setHealth(int newHealth)
{
	health = newHealth;
}
void Plant::setAttackDamage(int newAttackDamage)
{
	attackDamage = newAttackDamage;
}

int Plant::getCost() const
{
	return cost;
}
int Plant::getHealth() const
{
	return health;
}
int Plant::getAttackDamage() const
{
	return attackDamage;
}

