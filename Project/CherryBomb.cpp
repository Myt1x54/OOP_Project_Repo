#include "CherryBomb.h"

CherryBomb::CherryBomb(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/CherryBombSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
}

void CherryBomb::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

void CherryBomb::Blast()
{
    // will implement later
}

void CherryBomb::draw()
{
    window.draw(plantSprite);
}