#pragma once
#include <SFML/Graphics.hpp>

class ZombieFactory
{
protected:
    int health;
    int damage;
    sf::RenderWindow& window;
    sf::Image zombieImage;
    sf::Texture zombieTexture;
    sf::Sprite zombieSprite;

public:
    ZombieFactory(int newHealth, int newDamage, sf::RenderWindow& window);

    int getHealth() const;
    int getDamage() const;

    void setHealth(int newHealth);
    void setDamage(int newDamage);

    virtual void setPosition(float x, float y) = 0;
    virtual sf::Vector2f getPosition() const = 0;

    virtual void draw() = 0;

    virtual void Move() = 0;
};

