#include <SFML/Graphics.hpp>
#include "StartScreen.h"
#include <ctime>
StartScreen::StartScreen(sf::RenderWindow& window) : window(window)
{
    // Load background image
    backgroundimage.loadFromFile("../Images/start_background.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);

}
void StartScreen::draw()
{
    // Draw background
    window.draw(backgroundSprite);

    // Draw start text
    //window.draw(startText);
}

void StartScreen::display(sf::RenderWindow& window, StartScreen& screen)
{
	while (window.isOpen())
	{
		// Event handling
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Display the start screen
		screen.draw();
		window.display();

		// Check if the space key is pressed to start the game
		if (screen.isStartKeyPressed())
		{
			// Break out of the loop to start the game
			break;
		}
	}
}

bool StartScreen::isStartKeyPressed()
{
    // Check if space key is pressed
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}
