#include "SimpleZombie.h"
#include <cstdlib> 
#include <ctime>   

SimpleZombie::SimpleZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window) : Zombie(newHealth, newAttackDamage, window)
{
    // Load sprite for simple zombie
    zombieImage.loadFromFile("../Images/simple_zombie.png");
    zombieTexture.loadFromImage(zombieImage);
    zombieSprite.setTexture(zombieTexture);
}

void SimpleZombie::setPosition(float x, float y)
{
    zombieSprite.setPosition(x, y);
}

sf::Vector2f SimpleZombie::getPosition() const
{
    return zombieSprite.getPosition();
}

void SimpleZombie::draw()
{
    window.draw(zombieSprite);
}
//commentagain
void SimpleZombie::Move()
{
    sf::Vector2f zombie = getPosition();
    setPosition(zombie.x - 0.5f, zombie.y);
}

void SimpleZombie::DeleteZombie()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomRow = rand() % 5; // Choose a random row index between 0 and 4
    const float verticalDistance = (1034 - 125) / 5.0f;

    float zombieY = 30 + randomRow * verticalDistance + verticalDistance / 2;

    // Set the position of the zombie
    zombieSprite.setPosition(1900 + (rand() + 900) % 1500, zombieY);
}