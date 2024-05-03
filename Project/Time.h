#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class GameTime
{
private:
	Clock clock;
public:
	float getElapsedTime() const;
	void restartClock();
};

