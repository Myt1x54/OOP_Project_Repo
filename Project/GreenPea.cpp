#include "GreenPea.h"



GreenPea::GreenPea(sf::RenderWindow& window) : Pea(window)
{
    PeaImage.loadFromFile("../Images/GreenPea.png");
    PeaTexture.loadFromImage(PeaImage);
    PeaSprite.setTexture(PeaTexture);
}


void GreenPea::setPosition(float x, float y)
{
    PeaSprite.setPosition(x, y);
}

sf::Vector2f GreenPea::getPosition() const
{
    return PeaSprite.getPosition();
}

void GreenPea::draw()
{
    window.draw(PeaSprite);
}