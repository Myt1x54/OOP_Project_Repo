#include "FootballZombie.h"

FootballZombie::FootballZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window) : Zombie(newHealth, newAttackDamage, window)
{
    // Load sprite for simple zombie
    zombieImage.loadFromFile("../Images/PeaShooterSprite.png");
    zombieTexture.loadFromImage(zombieImage);
    zombieSprite.setTexture(zombieTexture);
}

void FootballZombie::setPosition(float x, float y)
{
    zombieSprite.setPosition(x, y);
}

sf::Vector2f FootballZombie::getPosition() const
{
    return zombieSprite.getPosition();
}

void FootballZombie::draw()
{
    window.draw(zombieSprite);
}