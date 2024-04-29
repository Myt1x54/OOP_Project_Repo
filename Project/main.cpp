﻿//#include <SFML/Graphics.hpp>
//#include <ctime>
//#include "StartScreen.h"
////#include"../SFML/Images/"
//using namespace sf;
//using namespace std;
//
//
//struct coordinats {
//	int x;
//	int y;
//};
//
//
//
////Drawing the background
//void createBack(RenderWindow& window) {
//	//Drawing the background
//	Image map_image;
//	map_image.loadFromFile("../Images/background.png");
//	Texture map;
//	map.loadFromImage(map_image);
//	Sprite s_map;
//	s_map.setTexture(map);
//	s_map.setPosition(0, 0);
//	window.draw(s_map);
//}
//
////Drawing the map
////void createMap(RenderWindow& window) {
////	//Drawing a map
////	Image map_image;//объект изображения для карты
////	map_image.loadFromFile("../Images/grid.png");//load the file for the map
////	Texture map;
////	map.loadFromImage(map_image);
////	Sprite s_map;
////	s_map.setTexture(map);
////	s_map.setPosition(347, 150);
////	window.draw(s_map);
////}
//
//
//int main()
//{
//	//Create a window, n*n
//	RenderWindow window(VideoMode::getFullscreenModes()[0], "Plants Vs Zombies", Style::Fullscreen);
//	//Game icon
//	Image icon;
//	if (!icon.loadFromFile("../Images/icon.png"))
//	{
//		return 1;
//	}
//	window.setIcon(32, 32, icon.getPixelsPtr());
//
//	///////////////////////////////////////
//
//	//Game field (5*9)
//	//Point 137*79 - leftmost point
//	//length 41; width 53
//	const int ROWS = 5;
//	const int COLS = 9;
//
//	bool FIELD_GAME_STATUS[ROWS][COLS];
//
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			FIELD_GAME_STATUS[i][j] = true;
//		}
//	}
//
//	Clock timeMoney;
//
//
//
//	Clock clock;
//
//	while (window.isOpen())
//	{
//		float time = clock.getElapsedTime().asMicroseconds();
//		float moneyTime = timeMoney.getElapsedTime().asSeconds();
//
//		clock.restart();
//		time = time / 800;
//
//		Event event;
//
//		
//		while (window.pollEvent(event))
//		{
//			
//
//			if (event.type == Event::Closed)
//				window.close();
//		}
//		
//
//		
//
//
//		//Create a background
//		createBack(window);
//		//createMap(window);
//
//
//
//
//		window.setSize(sf::Vector2u(1920, 1080));
//		window.display();
//	}
//	return 0;
//}


#include <SFML/Graphics.hpp>
#include <ctime>
#include "StartScreen.h"
using namespace sf;
using namespace std;

struct coordinats {
	int x;
	int y;
};

// Drawing the background
void createBack(RenderWindow& window) {
	// Drawing the background
	Image map_image;
	map_image.loadFromFile("../Images/background.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

int main()
{
	// Create a window, n*n
	RenderWindow window(VideoMode::getFullscreenModes()[0], "Plants Vs Zombies", Style::Fullscreen);

	// Game icon
	Image icon;
	if (!icon.loadFromFile("../Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	// Game field (5*9)
	const int ROWS = 5;
	const int COLS = 9;
	bool FIELD_GAME_STATUS[ROWS][COLS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	// Create a clock for time management
	Clock timeMoney;
	Clock clock;

	// Create an instance of the StartScreen class
	StartScreen startScreen(window);

	while (window.isOpen())
	{
		// Event handling
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Display the start screen
		startScreen.draw();
		window.display();

		// Check if the space key is pressed to start the game
		if (startScreen.isStartKeyPressed())
		{
			// Break out of the loop to start the game
			break;
		}
	}

	// Main game loop and logic go here
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Create a background
		createBack(window);

		window.setSize(sf::Vector2u(1920, 1080));
		window.display();
	}

	return 0;
}