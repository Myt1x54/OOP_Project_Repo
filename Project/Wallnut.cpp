#include "Wallnut.h"

Wallnut::Wallnut(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/WallnutSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
}

void Wallnut::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

void Wallnut::Roll()
{
    // will implement later
}

void Wallnut::draw()
{
    window.draw(plantSprite);
}