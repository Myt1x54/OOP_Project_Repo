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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mousePosition = sf::Mouse::getPosition(window);
        isMouseClicked = true;
    }
    if (isMouseClicked)
    {
        sf::sleep(sf::milliseconds(400)); // Adjust the delay as needed

        if (mousePosition.x >= 15 && mousePosition.x <= 625 && mousePosition.y >= 13 && mousePosition.y <= 500)
        {
            selectedOption = 0;
            return selectedOption;
        }
        else if (mousePosition.x >= 655 && mousePosition.x <= 1271 && mousePosition.y >= 13 && mousePosition.y <= 500)
        {
            selectedOption = 1;
            return selectedOption;
        }
        else if (mousePosition.x >= 1304 && mousePosition.x <= 1904 && mousePosition.y >= 13 && mousePosition.y <= 500)
        {
            selectedOption = 2;
            return selectedOption;
        }
        
        else if (mousePosition.x >= 15 && mousePosition.x <= 625 && mousePosition.y >= 532 && mousePosition.y <= 1062)
        {
            selectedOption = 3;
            return selectedOption;
        }
        else if (mousePosition.x >= 655 && mousePosition.x <= 1271 && mousePosition.y >= 532 && mousePosition.y <= 1062)
        {
            selectedOption = 4;
            return selectedOption;
        }
        else if (mousePosition.x >= 1304 && mousePosition.x <= 1904 && mousePosition.y >= 532 && mousePosition.y <= 1062)
        {
            selectedOption = 5;
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
        int selectedOption = stages.handleInput();
        if (selectedOption >= 0)
        {
            return selectedOption; // Return the selected option
        }
    }
    return -1; // Indicate no option selected
}
