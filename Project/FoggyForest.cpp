#include "FoggyForest.h"


FoggyForest::FoggyForest(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/FoggyForest.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
}

void FoggyForest::draw()
{
    window.draw(backgroundSprite);
}

int FoggyForest::display()
{
    while (window.isOpen()) {
        // Handle events specific to FoggyForest
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        draw(); // Draw the ZombiesOutskirts
        window.display();
        //
    }

    return -1; // Indicate no option selected
}