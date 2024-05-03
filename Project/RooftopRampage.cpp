#include "RooftopRampage.h"


RooftopRampage::RooftopRampage(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/RooftopRampage.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
}

void RooftopRampage::draw()
{
    window.draw(backgroundSprite);
}

int RooftopRampage::display()
{
    while (window.isOpen()) {
        // Handle events specific to RooftopRampage
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