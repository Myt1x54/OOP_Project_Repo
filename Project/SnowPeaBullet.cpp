#include "SnowPeaBullet.h"


SnowPeaBullet::SnowPeaBullet(sf::RenderWindow& window) : Pea(window)
{
    PeaImage.loadFromFile("../Images/SnowPea.png");
    PeaTexture.loadFromImage(PeaImage);
    PeaSprite.setTexture(PeaTexture);
}


void SnowPeaBullet::setPosition(float x, float y)
{
    PeaSprite.setPosition(x, y);
}

sf::Vector2f SnowPeaBullet::getPosition() const
{
    return PeaSprite.getPosition();
}

void SnowPeaBullet::draw()
{
    window.draw(PeaSprite);
}