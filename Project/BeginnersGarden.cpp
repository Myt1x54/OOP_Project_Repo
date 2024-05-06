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
    Plant* Plant[5];
    Plant[0] = new Peashooter(100, 125, 25, window);
    Plant[1] = new Sunflower(100, 125, 25, window);
    Plant[2] = new Repeater(100, 125, 25, window);
    Plant[3] = new Wallnut(100, 125, 25, window);
    Plant[4] = new SnowPea(100, 125, 25, window);
    // int i = 0;
    while (window.isOpen()) {
        // Handle events specific to BeginnersGarden
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        draw(); // Draw the BeginnersGarden
        Plant[0]->setPosition(506, 164);
        Plant[0]->draw();
        Plant[1]->setPosition(506 + (150 * 1), 164 + (180 * 1));
        Plant[1]->draw();
        Plant[2]->setPosition(506 + (150 * 2), 164 + (180 * 2));
        Plant[2]->draw();
        Plant[3]->setPosition(506 + (150 * 3) /* + i */, 164 + (180 * 3));
        Plant[3]->draw();
        Plant[4]->setPosition(506 + (150 * 4), 164 + (180 * 4));
        Plant[4]->draw();
        window.display();
        //
        // i =  i + 3;
    }

    return -1; // Indicate no option selected
}
