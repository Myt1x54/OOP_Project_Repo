#pragma once
#include<SFML/Graphics.hpp>
#include "Time.h"
using namespace std;
using namespace sf;
#include "Levels.h"
class ZombieOutskirts : public Levels
{
public:
	ZombieOutskirts(RenderWindow& window);

	void draw() override;

	int display() override;

	void setCurrency(int value);

	bool loseLife();

	~ZombieOutskirts();
};

