#pragma once
#include <SFML/Graphics.hpp>
#include "ZombieFactory.h"
using namespace std;
using namespace sf;
class PlantFactory
{
protected:
	int cost;
	int health;
	int attackDamage;
	sf::RenderWindow& window;
	sf::Image plantImage;
	sf::Texture plantTexture;
	sf::Sprite plantSprite;
	//animation stuff:
	sf::Clock animationClock;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int frameCount;
	float frameDuration;
public:

	PlantFactory(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void setCost(int newCost);
	void setHealth(int newHealth);
	void setAttackDamage(int newAttackDamage);

	int getCost() const;
	int getHealth() const;
	int getAttackDamage() const;

	virtual void setPosition(float x, float y) = 0;

	virtual sf::Vector2f getPosition() const = 0;

	virtual void updateSprite() = 0;

	virtual void draw() = 0;

	virtual void shootPea(ZombieFactory** zombie, int totalzombies) = 0;

	virtual void update() = 0;

	virtual void generateSun() = 0;

	virtual void setCurrency(int& currency) = 0;

	virtual bool isClicked(sf::Vector2f mousePosition) = 0;

	virtual void takeDamage() = 0;

	virtual bool isDestroyed() = 0;

	virtual float getLastHitTime() const = 0;

	virtual void setLastHitTime(float time) = 0;

	virtual void Roll() = 0;

	virtual bool isFinishedMoving() const = 0;

};

