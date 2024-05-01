#include "MainMenu.h"
#include<iostream>
using namespace std;

MainMenu::MainMenu(sf::RenderWindow& window)
    : window(window), selectedOption(0), isMouseClicked(false) {
    // Load menu image
    menuTexture.loadFromFile("../Images/StartMenu.png");
    menuSprite.setTexture(menuTexture);
    selectedOption = -1;
}

void MainMenu::draw() {
    window.draw(menuSprite);
}

int MainMenu::handleInput() 
{
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
            {
                mousePosition = sf::Mouse::getPosition(window);
                isMouseClicked = true;
            }
        if (isMouseClicked) 
        {
           
            if (mousePosition.x >= 690 && mousePosition.x <= 1240 && mousePosition.y >= 192 && mousePosition.y <= 285) 
            {
                // Mouse clicked within the "Start" button
                selectedOption = 0;
                return selectedOption;
            }
            else if (mousePosition.x >= 685 && mousePosition.x <= 1252 && mousePosition.y >= 315 && mousePosition.y <= 415) 
            {
                //cout << "moiz" << endl;
                // Mouse clicked within the "Instructions" button
                selectedOption = 1;
                return selectedOption;
            }
            else if (mousePosition.x >= 705 && mousePosition.x <= 1233 && mousePosition.y >= 437 && mousePosition.y <= 528) 
            {
                //cout << "moiz" << endl;
                // Mouse clicked within the "Scoreboard" button
                selectedOption = 2;
                return selectedOption;
            }
            isMouseClicked = false;
            return selectedOption;
            
        }
}
