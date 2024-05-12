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
    //animation stuff
    sf::Clock animationClock;
    int currentFrame;
    int frameWidth;
    int frameHeight;
    int frameCount;
    float frameDuration;
public:
    ZombieFactory(int newHealth, int newDamage, sf::RenderWindow& window);

    int getHealth() const;
    int getDamage() const;

    void setHealth(int newHealth);
    void setDamage(int newDamage);

    virtual void setPosition(float x, float y) = 0;
    virtual sf::Vector2f getPosition() const = 0;

    virtual void DeleteZombie() = 0;

    virtual void updateSprite() = 0;

    virtual void draw() = 0;

    virtual void Move() = 0;

    // Check if a given position collides with the zombie
    virtual bool checkCollision(const sf::Vector2f& position) const = 0;

    // Increment the hit counter of the zombie
    virtual void incrementHitCounter() = 0;
};

