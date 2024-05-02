#pragma once
#include <SFML/Graphics.hpp>
class StagesScreen
{
private:
    sf::RenderWindow& window;
    sf::Texture stageTexture;
    sf::Sprite stageSprite;
    sf::Vector2i mousePosition;
    bool isMouseClicked;
    int selectedOption; 
public:
    StagesScreen(sf::RenderWindow& window);

    void draw();
    int display(sf::RenderWindow& window, StagesScreen& stages);
    int handleInput();
};

