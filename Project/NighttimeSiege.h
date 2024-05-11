#pragma once
#include<SFML/Graphics.hpp>
#include "Time.h"
using namespace std;
using namespace sf;
#include "Levels.h"
class NighttimeSiege : public Levels
{
public:
	NighttimeSiege(RenderWindow& window);

	void draw() override;

	int display() override;

	void setCurrency(int value);

	~NighttimeSiege();
};

