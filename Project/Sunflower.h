#pragma once
#include <SFML/Graphics.hpp>
#include "Plant.h"
using namespace std;
using namespace sf;
class Sunflower : public Plant
{
public:
	Sunflower(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void generateSun();
};

