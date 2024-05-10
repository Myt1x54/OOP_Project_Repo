#pragma once
#include <SFML/Graphics.hpp>
#include "PlantFactory.h"
using namespace std;
using namespace sf;
class Plant : public PlantFactory
{
public:
	Plant();

	Plant(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	virtual void setPosition(float x, float y);

	virtual sf::Vector2f getPosition() const;

	virtual void draw();

	virtual void shootPea();

	virtual void update();

	//virtual int Display() = 0;


};

