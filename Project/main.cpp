//#include <SFML/Graphics.hpp>
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



// Drawing the background
//void createBack(RenderWindow& window) 
//{
//	// Drawing the background
//	Image map_image;
//	map_image.loadFromFile("../Images/background.png");
//	Texture map;
//	map.loadFromImage(map_image);
//	Sprite s_map;
//	s_map.setTexture(map);
//	s_map.setPosition(0, 0);
//	window.draw(s_map);
//}


	//// Create a window, n*n
	//RenderWindow window(VideoMode::getFullscreenModes()[0], "Plants Vs Zombies", Style::Fullscreen);

	//// Game icon
	//Image icon;
	//if (!icon.loadFromFile("../Images/icon.png"))
	//{
	//	return 1;
	//}
	//window.setIcon(32, 32, icon.getPixelsPtr());

	//// Game field (5*9)
	//const int ROWS = 5;
	//const int COLS = 9;
	//bool FIELD_GAME_STATUS[ROWS][COLS];
	//for (int i = 0; i < ROWS; i++) {
	//	for (int j = 0; j < COLS; j++) {
	//		FIELD_GAME_STATUS[i][j] = true;
	//	}
	//}

	//// Create a clock for time management
	//Clock timeMoney;
	//Clock clock;

	//// Create an instance of the StartScreen class
	//StartScreen startScreen(window);
	//startScreen.display(window, startScreen);
	//
	//MainMenu mainMenu(window);
	//StagesScreen stagesscreen(window);
	// while (window.isOpen())
	// {
 //       float time = clock.getElapsedTime().asMicroseconds();
 //       float moneyTime = timeMoney.getElapsedTime().asSeconds();

 //       clock.restart();
 //       time = time / 800;

 //       Event event;
 //       while (window.pollEvent(event))
 //       {
 //           if (event.type == Event::Closed)
 //               window.close();
 //       }

 //       // Display the main menu
 //       mainMenu.draw();
	//	int selectedOption = mainMenu.handleInput();
	//	int stageselect = stagesscreen.handleInput();
 //       // Perform actions based on the selected option
 //       switch (selectedOption)
 //       {
 //           case 0:
	//			stagesscreen.draw();
	//			switch (stageselect)
	//			{
	//				case 0:
	//					while (window.isOpen())
	//					{
	//						float time = clock.getElapsedTime().asMicroseconds();
	//						float moneyTime = timeMoney.getElapsedTime().asSeconds();

	//						clock.restart();
	//						time = time / 800;

	//						Event event;
	//						while (window.pollEvent(event))
	//						{
	//							if (event.type == Event::Closed)
	//								window.close();
	//						}

	//						// Create a background
	//						createBack(window);

	//						window.setSize(sf::Vector2u(1920, 1080));
	//						window.display();
	//					}
	//					break;
	//				case 1:
	//					// 2nd stage
	//					break;
	//				case 2:
	//					// 3rd stage
	//					break;
	//				case 3:
	//					// 4th stage
	//					break;
	//				case 4:
	//					// 5th stage
	//					break;
	//				case 5:
	//					// 6th stage
	//					break;
	//				default:
	//					break;
	//			}
 //               break;
 //           case 1:
 //               // Show instructions
 //               break;
 //           case 2:
 //               // Show scoreboard
 //               break;
 //           default:
 //               break;
 //       }

 //       window.display();
 //   }

#include <SFML/Graphics.hpp>
#include <ctime>
#include "StartScreen.h"
#include "MainMenu.h"
#include "StagesScreen.h"
#include "Game.h"
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


	Game game(window);
	game.run();
	return 0;
}


