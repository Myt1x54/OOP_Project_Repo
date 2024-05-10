#pragma once
#include <SFML/Graphics.hpp>
#include "Pea.h"
#include "SnowPeaBullet.h"
#include "Plant.h"
using namespace std;
using namespace sf;
class SnowPea : public Plant
{
private:
	Pea* snowPea;
	float counter;
public:
	SnowPea(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void shootPea();

	void update();

	~SnowPea();
};

