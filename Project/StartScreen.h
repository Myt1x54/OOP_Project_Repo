#pragma once
#include <SFML/Graphics.hpp>
class StartScreen
{
private:
    sf::RenderWindow& window;
    sf::Image backgroundimage;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text startText;
public:
    StartScreen(sf::RenderWindow& window);

    void draw();

    bool isStartKeyPressed();
};

