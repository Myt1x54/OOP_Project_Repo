#include "Time.h"

float GameTime::getElapsedTime() const
{
	return clock.getElapsedTime().asSeconds();
}
void GameTime::restartClock()
{
	clock.restart();
}