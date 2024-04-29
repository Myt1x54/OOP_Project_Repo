#include "StartScreen.h"
#include <SFML/Graphics.hpp>
StartScreen::StartScreen(sf::RenderWindow& window) : window(window)
{
    // Load background image
    backgroundimage.loadFromFile("../Images/start_background.jpg");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);

    //ola



    // Load font for text
    font.loadFromFile("../Images/Comic_Sans.ttf");

    // Set up start text
    startText.setFont(font);
    startText.setString("Press Space to Start");
    startText.setCharacterSize(30);
    startText.setFillColor(sf::Color::Red);
    startText.setPosition(950, 800);
}
void StartScreen::draw()
{
    // Draw background
    window.draw(backgroundSprite);

    // Draw start text
    //window.draw(startText);
}

bool StartScreen::isStartKeyPressed()
{
    // Check if space key is pressed
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}
