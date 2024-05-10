//#include "MainMenu.h"
//#include<iostream>
//using namespace std;
//
//MainMenu::MainMenu(sf::RenderWindow& window) : window(window), isMouseClicked(false) 
//{
//    // Load menu image
//    menuTexture.loadFromFile("../Images/StartMenu.png");
//    menuSprite.setTexture(menuTexture);
//    stageScreen = new StagesScreen(window);
//    selectedOption = -1;
//}
//
//void MainMenu::draw() 
//{
//    window.draw(menuSprite);
//}
//
//int MainMenu::handleInput() 
//{
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
//        {
//                mousePosition = sf::Mouse::getPosition(window);
//                isMouseClicked = true;
//        }
//        if (isMouseClicked) 
//        {
//            if (mousePosition.x >= 690 && mousePosition.x <= 1240 && mousePosition.y >= 192 && mousePosition.y <= 285) 
//            {
//                // Mouse clicked within the "Start" button
//                selectedOption = 0;
//                return selectedOption;
//            }
//            else if (mousePosition.x >= 685 && mousePosition.x <= 1252 && mousePosition.y >= 315 && mousePosition.y <= 415) 
//            {
//                //cout << "moiz" << endl;
//                // Mouse clicked within the "Instructions" button
//                selectedOption = 1;
//                return selectedOption;
//            }
//            else if (mousePosition.x >= 705 && mousePosition.x <= 1233 && mousePosition.y >= 437 && mousePosition.y <= 528) 
//            {
//                //cout << "moiz" << endl;
//                // Mouse clicked within the "Scoreboard" button
//                selectedOption = 2;
//                return selectedOption;
//            }
//            isMouseClicked = false;
//            return selectedOption;
//            
//        }
//}
//
//MainMenu::~MainMenu()
//{
//    delete stageScreen;
//}

#include "MainMenu.h"
#include<iostream>
using namespace std;
using namespace sf;






MainMenu::MainMenu(sf::RenderWindow& window) : window(window), isMouseClicked(false)
{
    // Load menu image
    menuTexture.loadFromFile("../Images/StartMenu.png");
    menuSprite.setTexture(menuTexture);
    selectedOption = -1;
}

void MainMenu::draw()
{
    window.draw(menuSprite);
}

int MainMenu::handleInput()
{
    bool mouse = 0;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mousePosition = sf::Mouse::getPosition(window);
        isMouseClicked = true;
    }
    if (isMouseClicked)
    {
        sf::sleep(sf::milliseconds(50)); // Adjust the delay as needed
        if (mousePosition.x >= 690 && mousePosition.x <= 1240 && mousePosition.y >= 192 && mousePosition.y <= 285)
        {
            selectedOption = 0;
            isMouseClicked = false;
            return selectedOption;
        }
        else if (mousePosition.x >= 685 && mousePosition.x <= 1252 && mousePosition.y >= 315 && mousePosition.y <= 415)
        {
            selectedOption = 1;
            isMouseClicked = false;
            return selectedOption;
        }
        else if (mousePosition.x >= 705 && mousePosition.x <= 1233 && mousePosition.y >= 437 && mousePosition.y <= 528)
        {
            selectedOption = 2;
            isMouseClicked = false;
            return selectedOption;
        }
        else if (mousePosition.x >= 1865 && mousePosition.x <= 1919 && mousePosition.y >= 0 && mousePosition.y <= 50)
        {
            selectedOption = 3;
            isMouseClicked = false;
            return selectedOption;
        }
        isMouseClicked = false;
        if (isMouseClicked == false)
        {
            return selectedOption;
        }
    }
    return -1;
}

int MainMenu::display(sf::RenderWindow& window, MainMenu& menu)
{
    
    while (window.isOpen())
    {
        // Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Draw the main menu
        menu.draw();
        window.display();

        // Handle input
        int selectedOption2 = menu.handleInput();
        if (selectedOption2 >= 0)
        {
            selectedOption = -1;
            return selectedOption2; // Return the selected option
        }
    }
    return -1; // Indicate no option selected
}


