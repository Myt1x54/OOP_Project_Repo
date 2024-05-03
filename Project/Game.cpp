#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;
using namespace sf;

void createBack(RenderWindow& window)
{
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

Game::Game(sf::RenderWindow& window) : window(window)
{
    mainMenu = new MainMenu(window);
    startScreen = new StartScreen(window);
    stagesScreen = mainMenu->getStageScreen();
    currentScreen = 0;
}

void Game::run()
{
    while (window.isOpen()) {
        switch (currentScreen) {
        case 0: // Start Screen
            runStartScreen();
            break;
        case 1: // Main Menu
            runMainMenu();
            break;
        case 2: // Stages Screen
            runStagesScreen();
            break;
        default:
            break;
        }
    }
}

void Game::runStartScreen()
{
    startScreen->display(window, *startScreen);

    while (!startScreen->isStartKeyPressed()) {
        handleEvents();
    }

    currentScreen = 1; // Switch to Main Menu after Start Screen
}

void Game::runMainMenu()
{
    mainMenu->draw();
    window.display();

    int selectedOption = mainMenu->handleInput();

    switch (selectedOption) {
    case 0: // Start game
        currentScreen = 2; // Switch to Stages Screen
        break;
    case 1: // Show instructions
        // Display instructions
        break;
    case 2: // Show scoreboard
        // Display scoreboard
        break;
    default:
        break;
    }
}

void Game::runStagesScreen()
{
    stagesScreen->draw();
    window.display();

    int selectedOption = stagesScreen->handleInput();

    switch (selectedOption) {
    case 0:
        while (window.isOpen())
        {
            Clock timeMoney;
            Clock clock;

            float time = clock.getElapsedTime().asMicroseconds();
            float moneyTime = timeMoney.getElapsedTime().asSeconds();

            clock.restart();
            time = time / 800;

            handleEvents();

            // Create a background
            createBack(window);

            window.setSize(sf::Vector2u(1920, 1080));
            window.display();
        }
        break;
    case 1:
        while (window.isOpen())
        {
            Clock timeMoney;
            Clock clock;

            float time = clock.getElapsedTime().asMicroseconds();
            float moneyTime = timeMoney.getElapsedTime().asSeconds();

            clock.restart();
            time = time / 800;

            handleEvents();

            // Create a background
            createBack(window);

            window.setSize(sf::Vector2u(1920, 1080));
            window.display();
        }
        break;
        // Add cases for other levels
    case 2:
        while (window.isOpen())
        {
            Clock timeMoney;
            Clock clock;

            float time = clock.getElapsedTime().asMicroseconds();
            float moneyTime = timeMoney.getElapsedTime().asSeconds();

            clock.restart();
            time = time / 800;

            handleEvents();

            // Create a background
            createBack(window);

            window.setSize(sf::Vector2u(1920, 1080));
            window.display();
        }
        break;
    case 3:
        while (window.isOpen())
        {
            Clock timeMoney;
            Clock clock;

            float time = clock.getElapsedTime().asMicroseconds();
            float moneyTime = timeMoney.getElapsedTime().asSeconds();

            clock.restart();
            time = time / 800;

            handleEvents();

            // Create a background
            createBack(window);

            window.setSize(sf::Vector2u(1920, 1080));
            window.display();
        }
        break;
    case 4:
        while (window.isOpen())
        {
            Clock timeMoney;
            Clock clock;

            float time = clock.getElapsedTime().asMicroseconds();
            float moneyTime = timeMoney.getElapsedTime().asSeconds();

            clock.restart();
            time = time / 800;

            handleEvents();

            // Create a background
            createBack(window);

            window.setSize(sf::Vector2u(1920, 1080));
            window.display();
        }
        break;
    case 5:
        while (window.isOpen())
        {
            Clock timeMoney;
            Clock clock;

            float time = clock.getElapsedTime().asMicroseconds();
            float moneyTime = timeMoney.getElapsedTime().asSeconds();

            clock.restart();
            time = time / 800;

            handleEvents();

            // Create a background
            createBack(window);

            window.setSize(sf::Vector2u(1920, 1080));
            window.display();
        }
        break;
    default:
        break;
    }
}

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

Game::~Game()
{
    delete startScreen;
    delete mainMenu;
    delete stagesScreen;
}
