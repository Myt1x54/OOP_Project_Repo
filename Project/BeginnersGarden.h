#pragma once
#include <SFML/Graphics.hpp>
#include "Time.h"
using namespace std;
using namespace sf;
#include "Levels.h"
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
class BeginnersGarden : public Levels
{
public:
	BeginnersGarden(RenderWindow& window);

	void draw() override;

	int display() override;

	void setCurrency(int value);

	~BeginnersGarden();
};

