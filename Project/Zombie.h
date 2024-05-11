#pragma once
#include <SFML/Graphics.hpp>
#include "ZombieFactory.h"
class Zombie : public ZombieFactory
{
public:
    
    Zombie();

    Zombie(int newHealth, int newAttackDamage, sf::RenderWindow& window);

    virtual void setPosition(float x, float y);

    virtual sf::Vector2f getPosition() const;

    virtual void DeleteZombie();

    virtual void draw();

    virtual void Move();
};

