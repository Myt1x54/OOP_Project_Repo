#pragma once
#include <SFML/Graphics.hpp>
#include "Pea.h"
#include "GreenPea.h"
#include "Plant.h"
using namespace std;
using namespace sf;
class Repeater : public Plant
{
private:
	Pea* greenPea;
	float counter;
public:
	Repeater(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void shootPea();

	void update();

	~Repeater();
};

