#include "SnowPea.h"


SnowPea::SnowPea(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/SnowPeaSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
}

void SnowPea::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

void SnowPea::shootPea()
{
    // will implement later
}

void SnowPea::draw()
{
    window.draw(plantSprite);
}