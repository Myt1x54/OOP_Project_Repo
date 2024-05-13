#include "Wallnut.h"
#include<iostream>
using namespace std;

Wallnut::Wallnut(int newCost, int newHealth, int newAttackDamage, RenderWindow& window, float initialX, float initialY) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/WallnutSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    generateTimer.restart();
    startPosition = sf::Vector2f(initialX, initialY);
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
    sf::Vector2f wallnutposition = getPosition();
    setPosition(wallnutposition.x + 0.5, wallnutposition.y);
}

void Wallnut::draw()
{
    window.draw(plantSprite);
}

void Wallnut::takeDamage()
{
    if (generateTimer.getElapsedTime().asSeconds() >= 3.0f) 
    {
        // Increment hitCount only if it's less than 10
        if (hitCount < 10) 
        {
            hitCount++;
        }
        generateTimer.restart(); // Restart the timer
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

bool Wallnut::isFinishedMoving() const
{
    // Get the current position of the Wallnut
    sf::Vector2f currentPosition = getPosition();

    // Calculate the destination position after rolling 3 squares
    float destinationX = startPosition.x + 3 * 150;
    float destinationY = startPosition.y; // No change in Y position

    // Check if the Wallnut has reached its destination
    if (currentPosition.x >= destinationX)
    {
        return true;
    }
    else
    {
        return false;
    }
}