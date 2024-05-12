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
	sf::Clock generateTimer;
	float counter;
	int hitCount;
	bool destroyed;
	float lastHitTime;
	float peaspeed;
public:
	Peashooter(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void updateSprite();

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void shootPea(ZombieFactory** zombie);

	void update();

	void takeDamage();

	bool isDestroyed();

	float getLastHitTime() const;

	void setLastHitTime(float time);
	
	~Peashooter();
};

