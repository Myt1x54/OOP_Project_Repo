#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>

class SimpleZombie : public Zombie
{
private:
	int hitCounter;
public:
	SimpleZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void updateSprite();

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void Move();

	void DeleteZombie();

	// Check if a given position collides with the zombie
	bool checkCollision(const sf::Vector2f& position) const;

	// Increment the hit counter of the zombie
	void incrementHitCounter();
};

