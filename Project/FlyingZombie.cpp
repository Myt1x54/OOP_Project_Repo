#include "FlyingZombie.h"

FlyingZombie::FlyingZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window) : Zombie(newHealth, newAttackDamage, window)
{
    // Load sprite for simple zombie
    zombieImage.loadFromFile("../Images/PeaShooterSprite.png");
    zombieTexture.loadFromImage(zombieImage);
    zombieSprite.setTexture(zombieTexture);
}

void FlyingZombie::setPosition(float x, float y)
{
    zombieSprite.setPosition(x, y);
}

sf::Vector2f FlyingZombie::getPosition() const
{
    return zombieSprite.getPosition();
}

void FlyingZombie::draw()
{
    window.draw(zombieSprite);
}
