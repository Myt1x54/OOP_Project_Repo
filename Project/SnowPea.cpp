#include "SnowPea.h"


SnowPea::SnowPea(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/SnowPeaSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
    snowPea = new SnowPeaBullet(window);
    counter = 0;
}

void SnowPea::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

sf::Vector2f SnowPea::getPosition() const
{
    return plantSprite.getPosition();
}

void SnowPea::update()
{
    shootPea();
}

void SnowPea::shootPea()
{
    if (snowPea != nullptr)
    {
        // Set  position
        sf::Vector2f peaPosition = plantSprite.getPosition();
        snowPea->setPosition(peaPosition.x + 100 + counter, peaPosition.y + 10);

        sf::Vector2f pea = snowPea->getPosition();
        if (pea.x >= 1890 && pea.y >= 100 && pea.x >= 1890 && pea.y <= 1031)
        {
            snowPea->setPosition(peaPosition.x + 100, peaPosition.y + 10);
            counter = 0;
        }

        snowPea->draw();

        // Update counter
        counter = counter + 2;
    }
}

void SnowPea::draw()
{
    window.draw(plantSprite);
}

SnowPea::~SnowPea()
{
    delete snowPea;
}