#include "ZombieOutskirts.h"



ZombieOutskirts::ZombieOutskirts(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/ZombieOutskirts.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
}

void ZombieOutskirts::draw()
{
    window.draw(backgroundSprite);
}

int ZombieOutskirts::display()
{
    while (window.isOpen()) {
        // Handle events specific to ZombiesOutskirts
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