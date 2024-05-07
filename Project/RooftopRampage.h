#pragma once
#include<SFML/Graphics.hpp>
#include "Time.h"
using namespace std;
using namespace sf;
#include "Levels.h"
class RooftopRampage : public Levels
{
public:
	RooftopRampage(RenderWindow& window);

	void draw() override;

	int display() override;

	~RooftopRampage();
};

