#include "Wallnut.h"

Wallnut::Wallnut(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/WallnutSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    generateTimer.restart();
    hitCount = 0;
    destroyed = false;
}

void Wallnut::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

sf::Vector2f Wallnut::getPosition() const
{
    return plantSprite.getPosition();
}

void Wallnut::Roll()
{
    // will implement later
}

void Wallnut::draw()
{
    window.draw(plantSprite);
}

void Wallnut::takeDamage()
{
    if (generateTimer.getElapsedTime().asSeconds() >= 20)
    {
        hitCount++;
    }
    if (hitCount >= 3)
    {
        destroyed = true;
    }
}

bool Wallnut::isDestroyed()
{
    return destroyed; // Return the value of the destroyed flag
}
