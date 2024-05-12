#include <SFML/Graphics.hpp>
#include "InstructionScreen.h"
InstructionScreen::InstructionScreen(sf::RenderWindow& window) : window(window)
{
	// Load background image
	backgroundimage.loadFromFile("../Images/Instruction.png");
	backgroundTexture.loadFromImage(backgroundimage);
	backgroundSprite.setTexture(backgroundTexture);

}
void InstructionScreen::draw()
{
	// Draw background
	window.draw(backgroundSprite);
}

int InstructionScreen::display(sf::RenderWindow& window, InstructionScreen& screen)
{
	while (window.isOpen())
	{
		// Event handling
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left) 
				{

					sf::Vector2i mousePosition = sf::Mouse::getPosition(window); 

					if (mousePosition.x >= 18 && mousePosition.x <= 382 && mousePosition.y >= 14 && mousePosition.y <= 127)
					{
						return 1;
						
					}
				}
			}
		}
		screen.draw();
		window.display();
	}
	return -1;
}

