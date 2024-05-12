#pragma once
#include <SFML/Graphics.hpp>
#include "Plant.h"
using namespace std;
using namespace sf;
class Sunflower : public Plant
{
private:
	int sunCount; // Data member to store the number of suns generated
	sf::Texture sunTexture; // Texture for the sun sprite
	sf::Sprite sunSprite; // Sprite for the sun
	sf::Clock generateTimer; // Timer for generating suns
	bool sunCollected;
	int hitCount;
	bool destroyed;
	float lastHitTime;
public:
	Sunflower(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void draw();

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void generateSun();

	void setCurrency(int& currency);

	bool isClicked(sf::Vector2f mousePosition);

	void takeDamage();

	bool isDestroyed();

	float getLastHitTime() const;

	void setLastHitTime(float time);
};


