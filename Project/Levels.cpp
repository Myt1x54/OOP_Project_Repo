#include "Levels.h"
Levels::Levels(RenderWindow& window) : window(window)
{
	plant = nullptr;
	gameTime = nullptr;
	zombie = nullptr;
	currency = 0;
	lives = 0;
}