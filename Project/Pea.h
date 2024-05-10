#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Pea
{
protected:
	sf::RenderWindow& window;
	sf::Image PeaImage;
	sf::Texture PeaTexture;
	sf::Sprite PeaSprite;
public:
	Pea(sf::RenderWindow& window);

	virtual void setPosition(float x, float y) = 0;

	virtual sf::Vector2f getPosition() const = 0;

	virtual void draw() = 0;
};

