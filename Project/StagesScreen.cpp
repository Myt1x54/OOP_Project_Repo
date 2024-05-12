#include "StagesScreen.h"
#include<iostream>
using namespace std;
using namespace sf;

StagesScreen::StagesScreen(sf::RenderWindow& window) : window(window)
{
	isMouseClicked = 0;
	selectedOption = -1;
	stageTexture.loadFromFile("../Images/StageSelect.png");
	stageSprite.setTexture(stageTexture);
}

void StagesScreen::draw()
{
	window.draw(stageSprite);
}
int StagesScreen::handleInput()
{   
    bool mouse = 0;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mousePosition = sf::Mouse::getPosition(window);
        isMouseClicked = true;
    }
    if (isMouseClicked)
    {
        sf::sleep(sf::milliseconds(100)); // Adjust the delay as needed

        if (mousePosition.x >= 70 && mousePosition.x <= 650 && mousePosition.y >= 68 && mousePosition.y <= 500)
        {
            selectedOption = 0;
            return selectedOption;
        }
        else if (mousePosition.x >= 680 && mousePosition.x <= 1272 && mousePosition.y >= 68 && mousePosition.y <= 500)
        {
            selectedOption = 1;
            return selectedOption;
        }
        else if (mousePosition.x >= 1304 && mousePosition.x <= 1878 && mousePosition.y >= 68 && mousePosition.y <= 500)
        {
            selectedOption = 2;
            return selectedOption;
        }
        
        else if (mousePosition.x >= 70 && mousePosition.x <= 650 && mousePosition.y >= 532 && mousePosition.y <= 1054)
        {
            selectedOption = 3;
            return selectedOption;
        }
        else if (mousePosition.x >= 680 && mousePosition.x <= 1272 && mousePosition.y >= 532 && mousePosition.y <= 1062)
        {
            selectedOption = 4;
            return selectedOption;
        }
        else if (mousePosition.x >= 1304 && mousePosition.x <= 1878 && mousePosition.y >= 532 && mousePosition.y <= 1062)
        {
            selectedOption = 5;
            return selectedOption;
        }
        else if (mousePosition.x >= 11 && mousePosition.x <= 190 && mousePosition.y >= 4 && mousePosition.y <= 61)
        {
            selectedOption = 6;
            return selectedOption;
        }
        isMouseClicked = false;
        return selectedOption;
    }
    
    return -1;
}
int StagesScreen::display(sf::RenderWindow& window, StagesScreen& stages)
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

        // Draw the stage screen
        stages.draw();
        window.display();

        // Handle input
       
        int selectedOption2 = stages.handleInput();
        
        if (selectedOption2 >= 0)
        {
            selectedOption = -1;
            return selectedOption2; // Return the selected option
        }
    }
    return -1; // Indicate no option selected
}
