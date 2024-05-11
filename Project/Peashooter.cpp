#include "Peashooter.h"
#include<iostream>
using namespace std;
Peashooter::Peashooter(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load Sprite for Peashooter
    plantImage.loadFromFile("../Images/PeaShooterSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    greenPea = new GreenPea(window);
    counter = 0;
    
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
                }
            }
        }


        // Update counter
        counter = counter + 2;
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