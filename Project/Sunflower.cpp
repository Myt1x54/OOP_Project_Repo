#include "Sunflower.h"


Sunflower::Sunflower(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/SunflowerSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
}

void Sunflower::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

void Sunflower::generateSun()
{
    // will do later
}

void Sunflower::draw()
{
    window.draw(plantSprite);
}