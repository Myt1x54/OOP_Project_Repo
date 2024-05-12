#pragma once
#include <SFML/Graphics.hpp>
#include "Plant.h"
using namespace std;
using namespace sf;
class Wallnut : public Plant
{
private:
	sf::Clock generateTimer;
	int hitCount;
	bool destroyed;
	sf::Vector2f startPosition;
public:
	Wallnut(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window, float initialX, float initialY);

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void takeDamage();

	bool isDestroyed();

	void Roll();

	bool isFinishedMoving() const;
};

