#pragma once
#include <SFML/Graphics.hpp>
#include "Plant.h"
using namespace std;
using namespace sf;
class SnowPea : public Plant
{
public:
	SnowPea(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void shootPea();
};

