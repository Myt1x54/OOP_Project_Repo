#include "DancingZombie.h"

DancingZombie::DancingZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window) : Zombie(newHealth, newAttackDamage, window)
{
    // Load sprite for simple zombie
    zombieImage.loadFromFile("../Images/PeaShooterSprite.png");
    zombieTexture.loadFromImage(zombieImage);
    zombieSprite.setTexture(zombieTexture);
}

void DancingZombie::setPosition(float x, float y)
{
    zombieSprite.setPosition(x, y);
}

sf::Vector2f DancingZombie::getPosition() const
{
    return zombieSprite.getPosition();
}

void DancingZombie::draw()
{
    window.draw(zombieSprite);
}