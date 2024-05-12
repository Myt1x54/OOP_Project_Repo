#include "CherryBomb.h"

CherryBomb::CherryBomb(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/CherryBombSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    GenerateTimer.restart();
    hitcount = 0;
    Destroyed = false;
}

void CherryBomb::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

sf::Vector2f CherryBomb::getPosition() const
{
    return plantSprite.getPosition();
}

void CherryBomb::Blast()
{
    // will implement later
}

void CherryBomb::draw()
{
    window.draw(plantSprite);
}

void CherryBomb::takeDamage()
{
    if (GenerateTimer.getElapsedTime().asSeconds() >= 3.0f)
    {
        // Increment hitCount only if it's less than 10
        if (hitcount < 2)
        {
            hitcount++;
        }
        GenerateTimer.restart(); // Restart the timer after incrementing hitCount
    }

    if (hitcount >= 10)
    {
        Destroyed = true;
    }
}

bool CherryBomb::isDestroyed()
{
    return Destroyed; // Return the value of the destroyed flag
}
