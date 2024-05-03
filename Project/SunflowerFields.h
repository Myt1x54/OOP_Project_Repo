#pragma once
#include<SFML/Graphics.hpp>
#include "Time.h"
using namespace std;
using namespace sf;
#include "Levels.h"
class SunflowerFields : public Levels
{
public:
	SunflowerFields(RenderWindow& window);

	void draw() override;

	int display() override;
};

