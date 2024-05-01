#pragma once
#include <SFML/Graphics.hpp>
class StartScreen
{
private:
    sf::RenderWindow& window;
    sf::Image backgroundimage;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
public:
    StartScreen(sf::RenderWindow& window);

    void draw();

    void display(sf::RenderWindow& window, StartScreen& screen);

    bool isStartKeyPressed();
};

