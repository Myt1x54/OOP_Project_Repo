#include "Repeater.h"


Repeater::Repeater(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/RepeaterSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    greenPea = new GreenPea(window);
    counter = 0;
}

void Repeater::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

sf::Vector2f Repeater::getPosition() const
{
    return plantSprite.getPosition();
}

void Repeater::update()
{
    shootPea();
}

void Repeater::shootPea()
{
    if (greenPea != nullptr)
    {
        // Create a new GreenPea instance

        // Set its position
        sf::Vector2f peaPosition = plantSprite.getPosition();
        greenPea->setPosition(peaPosition.x + 100 + counter, peaPosition.y + 10); // Set initial position

        sf::Vector2f pea = greenPea->getPosition();
        if (pea.x >= 1890 && pea.y >= 100 && pea.x >= 1890 && pea.y <= 1031)
        {
            greenPea->setPosition(peaPosition.x + 100, peaPosition.y + 10);
            counter = 0;
        }

        // Draw the GreenPea
        greenPea->draw();

        // Update counter
        counter = counter + 2;
    }
}

void Repeater::draw()
{
    window.draw(plantSprite);
}


Repeater::~Repeater()
{
    delete greenPea;
}