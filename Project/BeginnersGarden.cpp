#include "BeginnersGarden.h"


BeginnersGarden::BeginnersGarden(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/BeginnersGarden.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
}

void BeginnersGarden::draw()
{
    window.draw(backgroundSprite);
}

int BeginnersGarden::display()
{
    while (window.isOpen()) {
        // Handle events specific to BeginnersGarden
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // Add more event handling if needed
        }

        draw(); // Draw the BeginnersGarden
        window.display();
        //
    }

    return -1; // Indicate no option selected
}
