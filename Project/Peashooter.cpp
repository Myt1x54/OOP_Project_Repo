#include "Peashooter.h"
#include<iostream>
using namespace std;
Peashooter::Peashooter(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load Sprite for Peashooter
    plantImage.loadFromFile("../Images/peashooterAnimationSmaller.png");
    //plantImage.loadFromFile("../Images/peashooterAnimationSmaller.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    plantSprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    greenPea = new GreenPea(window);
    generateTimer.restart();
    counter = 0;
    hitCount = 0;
    destroyed = false;
    lastHitTime = 0;
    peaspeed = (rand() % 4) + 1;
}
//yo
void Peashooter::updateSprite() {
    // Calculate the width and height of each frame
    int frameWidth = 2200 / 22;
    int frameHeight = 100 / 1;

    // Calculate the number of frames in the sprite sheet
    int frameCount = 22 * 1;

    // Check if it's time to update the frame
    if (animationClock.getElapsedTime().asSeconds() > frameDuration) {
        // Move to the next frame
        currentFrame = (currentFrame + 1) % frameCount;

        // Calculate the offset for the current frame
        int column = currentFrame % 22;
        int row = currentFrame / 22;
        int offsetX = column * frameWidth;
        int offsetY = row * frameHeight;

        // Update the texture rectangle
        plantSprite.setTextureRect(sf::IntRect(offsetX, offsetY, frameWidth, frameHeight));

        // Restart the animation clock
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
    if (generateTimer.getElapsedTime().asSeconds() >= peaspeed) // Adjust the reload time here (2.0f represents 2 seconds)
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
    if (generateTimer.getElapsedTime().asSeconds() >= 3.0f)
    {
        // Increment hitCount only if it's less than 10
        if (hitCount < 4)
        {
            hitCount++;
        }
        generateTimer.restart(); // Restart the timer after incrementing hitCount
    }

    if (hitCount >= 4)
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