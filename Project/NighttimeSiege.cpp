#include "NighttimeSiege.h"


NighttimeSiege::NighttimeSiege(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/NighttimeSeige.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
}

void NighttimeSiege::draw()
{
    window.draw(backgroundSprite);
}

int NighttimeSiege::display()
{
    while (window.isOpen()) {
        // Handle events specific to NighttimeSiege
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