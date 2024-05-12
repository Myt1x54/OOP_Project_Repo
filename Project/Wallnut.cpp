#include "Wallnut.h"
#include<iostream>
using namespace std;

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
    if (generateTimer.getElapsedTime().asSeconds() >= 6.0f) 
    {
        cout << "moiz" << endl;
        // Increment hitCount only if it's less than 10
        if (hitCount < 10) 
        {
            hitCount++;
        }
        generateTimer.restart(); // Restart the timer after incrementing hitCount
    }

    if (hitCount >= 10) 
    {
        destroyed = true;
    }
}

bool Wallnut::isDestroyed()
{
    return destroyed; // Return the value of the destroyed flag
}
