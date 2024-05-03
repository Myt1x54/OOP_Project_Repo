#include "SunflowerFields.h"


SunflowerFields::SunflowerFields(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/SunflowerField.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
}

void SunflowerFields::draw()
{
    window.draw(backgroundSprite);
}

int SunflowerFields::display()
{
    while (window.isOpen()) {
        // Handle events specific to SunflowerFields
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