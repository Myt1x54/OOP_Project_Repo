#include "Peashooter.h"
#include<iostream>
using namespace std;
Peashooter::Peashooter(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load Sprite for Peashooter
    //plantImage.loadFromFile("../Images/img6.png");
    plantImage.loadFromFile("../Images/peashooterAnimation.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    plantSprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    greenPea = new GreenPea(window);
    generateTimer.restart();
    counter = 0;
    hitCount = 0;
    destroyed = false;
    lastHitTime = 0;
}

void Peashooter::updateSprite() 
{
    if (animationClock.getElapsedTime().asSeconds() > frameDuration)
    {
        currentFrame = (currentFrame + 1) % frameCount;
        int offsetX = currentFrame * frameWidth;
        plantSprite.setTextureRect(sf::IntRect(offsetX, 0, frameWidth, frameHeight)); // Update texture rectangle
        animationClock.restart();
    }
}

void Peashooter::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

sf::Vector2f Peashooter::getPosition() const
{
    return plantSprite.getPosition();
}

void Peashooter::update()
{
    // nothing
}

void Peashooter::shootPea(ZombieFactory** zombie)
{
    // Check if enough time has elapsed since the last shot
    if (generateTimer.getElapsedTime().asSeconds() >= 2.0f) // Adjust the reload time here (2.0f represents 2 seconds)
    {
        if (greenPea != nullptr)
        {
            // Create a new GreenPea instance

            // Set its position
            sf::Vector2f peaPosition = plantSprite.getPosition();
            greenPea->setPosition(peaPosition.x + 100 + counter, peaPosition.y + 10); // Set initial position

            sf::Vector2f pea = greenPea->getPosition();
            if (pea.x >= 1890 && pea.y >= 100 && pea.x >= 1890 && pea.y <= 1031)
            {
                greenPea->setPosition(peaPosition.x + 100, peaPosition.y + 10);
                counter = 0;
            }

            // Draw the GreenPea
            greenPea->draw();

            // Check for collision with each zombie
            for (int i = 0; i < 5; ++i)
            {
                if (zombie[i] != nullptr)
                {
                    if (zombie[i]->checkCollision(pea))
                    {
                        // Reset the position of the pea
                        greenPea->setPosition(peaPosition.x + 100, peaPosition.y + 10);
                        counter = 0;

                        // Increment the hit counter of the zombie
                        zombie[i]->incrementHitCounter();

                        // Restart the reload timer
                        generateTimer.restart();
                        return; // Exit the function early since a shot was fired
                    }
                }
            }

            // Update counter
            counter = counter + 2;
        }
    }
}

void Peashooter::draw()
{
    window.draw(plantSprite);
}

Peashooter::~Peashooter()
{
        delete greenPea;
}

void Peashooter::takeDamage()
{
    if (generateTimer.getElapsedTime().asSeconds() >= 9)
    {
        hitCount++;
    }
    if (hitCount >= 6) 
    {
        destroyed = true;
    }
}

bool Peashooter::isDestroyed()
{
    return destroyed; // Return the value of the destroyed flag
}

float Peashooter::getLastHitTime() const
{
    return lastHitTime;
}

void Peashooter::setLastHitTime(float time)
{
    lastHitTime = time;
}