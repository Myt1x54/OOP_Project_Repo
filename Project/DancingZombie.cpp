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
    // Define a clock to track time for direction changes
    static sf::Clock directionClock;
    static float directionChangeInterval = 3.0f + (rand() % 2); // Random interval between 3 to 4 seconds

    static bool movingUp = false;

    float elapsedSeconds = directionClock.getElapsedTime().asSeconds();

    // Check if it's time to change direction
    if (elapsedSeconds >= directionChangeInterval) 
    {
        // Randomly determine the new direction
        movingUp = rand() % 2 == 0; // Randomly decide whether to move up or down
        directionChangeInterval = 3.0f + (rand() % 2); // Randomize the interval again

        // Restart the clock
        directionClock.restart();
    }

    // Get current zombie position
    sf::Vector2f zombiePos = getPosition();

    // Calculate the new position by moving diagonally
    float newX = zombiePos.x - 0.5f; // Move left horizontally

    // Check if the zombie should move up or down based on the flag
    float newY = zombiePos.y;
    if (movingUp) 
    {
        newY -= 0.5f * elapsedSeconds; // Move up vertically
    }
    else 
    {
        newY += 0.5f * elapsedSeconds; // Move down vertically
    }

    // Limit to the top and bottom of screen
    if (newY < 288) 
    {
        newY = 288; // Limit movement to the top edge of the screen
        movingUp = false; // Change direction to move down
    }
    else if (newY > 885) 
    {
        newY = 885; // Limit to the bottom of screen
        movingUp = true; // Change direction to move up
    }

    setPosition(newX, newY);
}

void DancingZombie::DeleteZombie()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    // Variables to store the previous zombie positions
    static float prevX = 0.0f;
    static float prevY = 0.0f;

    int randomRow;
    float zombieY;

    // Generate new position
    do {
        randomRow = rand() % 5; // Choose a random row index between 0 and 4
        const float verticalDistance = (1034 - 125) / 5.0f;
        zombieY = 30 + randomRow * verticalDistance + verticalDistance / 2;
    } while (abs(zombieY - prevY) < 100.0f); // Ensure sufficient difference in Y position

    zombieSprite.setPosition(1900 + (rand() + 900) % 1500, zombieY);

    // Update previous position variables
    prevX = zombieSprite.getPosition().x;
    prevY = zombieY;
}

bool DancingZombie::checkCollision(const sf::Vector2f& position) const
{
    const float zombieWidth = 150.0f;
    const float zombieHeight = 150.0f;

    sf::Vector2f zombiePosition = getPosition();

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