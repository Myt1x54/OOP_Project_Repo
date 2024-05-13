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

	virtual void updateSprite();

	virtual void draw();

	virtual void shootPea(ZombieFactory** zombie, int totalzombies);

	virtual void update();

	virtual void generateSun();

	virtual void setCurrency(int& currency);

	virtual bool isClicked(sf::Vector2f mousePosition);

	virtual void takeDamage();

	virtual bool isDestroyed();

	virtual float getLastHitTime() const;

	virtual void setLastHitTime(float time);

	virtual void Roll();

	virtual bool isFinishedMoving() const;

	//virtual int Display() = 0;


};

