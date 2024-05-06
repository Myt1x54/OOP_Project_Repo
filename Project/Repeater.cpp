#include "Repeater.h"


Repeater::Repeater(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/RepeaterSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
}

void Repeater::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

void Repeater::shootPea()
{
    // will implement later
}

void Repeater::draw()
{
    window.draw(plantSprite);
}