#pragma once
#include <SFML/Graphics.hpp>
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

	virtual void draw() = 0;

	virtual void shootPea() = 0;

	virtual void update() = 0;

};

