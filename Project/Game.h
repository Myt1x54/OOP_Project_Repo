#pragma once
#include <SFML/Graphics.hpp>
#include "StartScreen.h"
#include "MainMenu.h"
#include "InstructionScreen.h"
#include "StagesScreen.h"
#include "Levels.h"
#include "BeginnersGarden.h"
#include "ZombieOutskirts.h"
#include "SunflowerFields.h"
#include "FoggyForest.h"
#include "NighttimeSiege.h"
#include "RooftopRampage.h"
#include "Plant.h"
#include "Peashooter.h"
class Game
{
private:
	sf::RenderWindow& window;
	MainMenu* mainMenu;
	StartScreen* startScreen;
	StagesScreen* stagesScreen;
	InstructionScreen* instructionScreen;
	int currentScreen;
public:
	Game(sf::RenderWindow& window);

	void run();

	void runStartScreen();

	void runMainMenu();

	void runInstructionScreen();

	void runStagesScreen();

	void handleEvents();

	~Game();

};

