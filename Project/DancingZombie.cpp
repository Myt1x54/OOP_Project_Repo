#include "DancingZombie.h"

DancingZombie::DancingZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window) : Zombie(newHealth, newAttackDamage, window)
{
    // Load sprite for simple zombie
    zombieImage.loadFromFile("../Images/dancingzombie.png");
    zombieTexture.loadFromImage(zombieImage);
    zombieSprite.setTexture(zombieTexture);
    hitCounter = 0;
}

void DancingZombie::setPosition(float x, float y)
{
    zombieSprite.setPosition(x, y);
}

sf::Vector2f DancingZombie::getPosition() const
{
    return zombieSprite.getPosition();
}

void DancingZombie::draw()
{
    window.draw(zombieSprite);
}


void DancingZombie::Move()
{
    sf::Vector2f zombie = getPosition();
    setPosition(zombie.x - 0.5f, zombie.y);
}

void DancingZombie::DeleteZombie()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    // Variables to store the previous zombie positions
    static float prevX = 0.0f;
    static float prevY = 0.0f;

    int randomRow;
    float zombieY;

    // Generate a new position until it's sufficiently different from the previous one
    do {
        randomRow = rand() % 5; // Choose a random row index between 0 and 4
        const float verticalDistance = (1034 - 125) / 5.0f;
        zombieY = 30 + randomRow * verticalDistance + verticalDistance / 2;
    } while (abs(zombieY - prevY) < 100.0f); // Ensure sufficient difference in Y position

    // Set the position of the zombie
    zombieSprite.setPosition(1900 + (rand() + 900) % 1500, zombieY);

    // Update previous position variables
    prevX = zombieSprite.getPosition().x;
    prevY = zombieY;
}


// Check if a given position collides with the zombie
bool DancingZombie::checkCollision(const sf::Vector2f& position) const
{
    const float zombieWidth = 150.0f;
    const float zombieHeight = 150.0f;

    // Get the position of the zombie
    sf::Vector2f zombiePosition = getPosition(); // Assuming getPosition() returns the position of the zombie

    // Check if the pea position overlaps with the zombie's bounding box
    if (position.x >= zombiePosition.x && position.x <= zombiePosition.x + zombieWidth &&
        position.y >= zombiePosition.y && position.y <= zombiePosition.y + zombieHeight)
    {
        return true; // Collision detected
    }

    return false; // No collision
}

// Increment the hit counter of the zombie
void DancingZombie::incrementHitCounter()
{
    hitCounter++;
    if (hitCounter == 4)
    {
        DeleteZombie();
        hitCounter = 0;
    }
}