#pragma once
#include <SFML/Graphics.hpp>
#include "Pea.h"
#include "GreenPea.h"
#include "Plant.h"
#include "ZombieFactory.h"
using namespace std;
using namespace sf;

class Peashooter : public Plant
{
private:
	Pea* greenPea;
	float counter;
public:
	Peashooter(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void shootPea(ZombieFactory** zombie);

	void update();

	~Peashooter();
};

