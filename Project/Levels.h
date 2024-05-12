#pragma once
#include <SFML/Graphics.hpp>
#include "Time.h"
#include "PlantFactory.h"
#include "Plant.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Repeater.h"
#include "Wallnut.h"
#include "SnowPea.h"
#include "CherryBomb.h"
#include "ZombieFactory.h"
#include "Zombie.h"
#include "SimpleZombie.h"
using namespace std;
using namespace sf;
class Levels
{
protected:
    sf::RenderWindow& window;
    sf::Image backgroundimage;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    PlantFactory** plant;
	GameTime* gameTime;
    ZombieFactory** zombie;
    int currency;
    int lives;
    sf::Font font;
    sf::Text currencyText;
    sf::Font livefont;
    sf::Text LivesText;
public:
    Levels(RenderWindow& window);

    // Pure virtual destructor
    virtual ~Levels() {}

    virtual void draw() = 0;
    virtual int display() = 0;
    virtual void setCurrency(int value) = 0;

};

