#pragma once
#include <SFML/Graphics.hpp>
#include "Pea.h"
using namespace std;
using namespace sf;
class GreenPea : public Pea
{
public:
	GreenPea(sf::RenderWindow& window);

	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;

	void draw();
};

