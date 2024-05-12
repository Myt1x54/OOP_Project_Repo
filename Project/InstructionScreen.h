#pragma once
#include <SFML/Graphics.hpp>
class InstructionScreen
{
private:
    sf::RenderWindow& window;
    sf::Image backgroundimage;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
public:
    InstructionScreen(sf::RenderWindow& window);

    void draw();

    int display(sf::RenderWindow& window, InstructionScreen& screen);
};

