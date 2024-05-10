#include "SimpleZombie.h"

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

void SimpleZombie::Move()
{
    zombieSprite.move(-0.5f, 0.0f);
}
