#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Plant
{
protected:
	int cost;
	int health;
	int attackDamage;
	sf::RenderWindow& window;
	sf::Image plantImage;
	sf::Texture plantTexture;
	sf::Sprite plantSprite;
public:
	Plant(int newCost, int newHealth, int newAttackDamage, sf::RenderWindow& window);

	void setCost(int newCost);
	void setHealth(int newHealth);
	void setAttackDamage(int newAttackDamage);

	int getCost() const;
	int getHealth() const;
	int getAttackDamage() const;

	virtual void setPosition(float x, float y) = 0;

	virtual void draw() = 0;

	//virtual int Display() = 0;


};

