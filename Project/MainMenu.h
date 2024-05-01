#pragma once
#include <SFML/Graphics.hpp>
class MainMenu
{
private:
    sf::RenderWindow& window;
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    sf::Vector2i mousePosition;
    bool isMouseClicked;
    int selectedOption; // 0 for Start, 1 for Instructions, 2 for Scoreboard
public:
    MainMenu(sf::RenderWindow& window);

    void draw();
    int handleInput();
};

