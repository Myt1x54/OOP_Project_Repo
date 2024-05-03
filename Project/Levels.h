#pragma once
#include <SFML/Graphics.hpp>
#include "Time.h"
using namespace std;
using namespace sf;
class Levels
{
protected:
    sf::RenderWindow& window;
    sf::Image backgroundimage;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
	GameTime* gameTime;
public:
    Levels(RenderWindow& window);

    // Pure virtual destructor
    virtual ~Levels() {}

    virtual void draw() = 0;
    virtual int display() = 0;
};

