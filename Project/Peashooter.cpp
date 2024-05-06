#include "Peashooter.h"

Peashooter::Peashooter(int newCost, int newHealth, int newAttackDamage, RenderWindow& window) : Plant(newCost, newHealth, newAttackDamage, window)
{
    // Load background image for BeginnersGarden
    plantImage.loadFromFile("../Images/PeaShooterSprite.png");
    plantTexture.loadFromImage(plantImage);
    plantSprite.setTexture(plantTexture);
}

void Peashooter::setPosition(float x, float y)
{
    plantSprite.setPosition(x, y);
}

void Peashooter::shootPea()
{
    // will implement later
}

void Peashooter::draw()
{
    window.draw(plantSprite);
}
