#pragma once
#include<SFML/Graphics.hpp>
#include "Time.h"
using namespace std;
using namespace sf;
#include "Levels.h"
class FoggyForest : public Levels
{
public:
	FoggyForest(RenderWindow& window);

	void draw() override;

	int display() override;

	~FoggyForest();
};

