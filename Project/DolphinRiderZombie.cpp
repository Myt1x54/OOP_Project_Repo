#include "DolphinRiderZombie.h"

DolphinRiderZombie::DolphinRiderZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window) : Zombie(newHealth, newAttackDamage, window)
{
    // Load sprite for simple zombie
    zombieImage.loadFromFile("../Images/PeaShooterSprite.png");
    zombieTexture.loadFromImage(zombieImage);
    zombieSprite.setTexture(zombieTexture);
}

void DolphinRiderZombie::setPosition(float x, float y)
{
    zombieSprite.setPosition(x, y);
}

sf::Vector2f DolphinRiderZombie::getPosition() const
{
    return zombieSprite.getPosition();
}

void DolphinRiderZombie::draw()
{
    window.draw(zombieSprite);
}