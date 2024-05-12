#include <SFML/Graphics.hpp>
#include <ctime>
#include "StartScreen.h"
#include "MainMenu.h"
#include "StagesScreen.h"
#include "Game.h"
#include "Plant.h"
using namespace sf;
using namespace std;

struct coordinats {
	int x;
	int y;
};

int main()
{
	 
	
	// Create a window, n* n
	RenderWindow window(VideoMode::getFullscreenModes()[0], "Plants Vs Zombies", Style::Fullscreen);
	//Game icon
	Image icon;
	if (!icon.loadFromFile("../Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());


	Game* game = new Game(window);
	game->run();

	delete game;
	return 0;
}


