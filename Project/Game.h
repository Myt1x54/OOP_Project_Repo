#pragma once
#include <SFML/Graphics.hpp>
#include "StartScreen.h"
#include "MainMenu.h"
#include "StagesScreen.h"
#include "BeginnersGarden.h"
class Game
{
private:
	sf::RenderWindow& window;
	MainMenu* mainMenu;
	StartScreen* startScreen;
	StagesScreen* stagesScreen;
	int currentScreen;
public:
	Game(sf::RenderWindow& window);

	void run();

	void runStartScreen();

	void runMainMenu();

	void runStagesScreen();

	void handleEvents();

	//void runStages();

	~Game();

};

