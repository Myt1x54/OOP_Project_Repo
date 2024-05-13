#include "FootballZombie.h"

FootballZombie::FootballZombie(int newHealth, int newAttackDamage, sf::RenderWindow& window) : Zombie(newHealth, newAttackDamage, window)
{
    // Load sprite for simple zombie
    zombieImage.loadFromFile("../Images/footballzombie.png");
    zombieTexture.loadFromImage(zombieImage);
    zombieSprite.setTexture(zombieTexture);
    hitCounter = 0;
}

void FootballZombie::setPosition(float x, float y)
{
    zombieSprite.setPosition(x, y);
}

sf::Vector2f FootballZombie::getPosition() const
{
    return zombieSprite.getPosition();
}

void FootballZombie::draw()
{
    window.draw(zombieSprite);
}

void FootballZombie::Move()
{
    // Initialize static variables to keep track of time
    static sf::Clock clock;
    static float elapsedTime = 0.0f;

    // Get elapsed time since last movement
    float deltaTime = clock.getElapsedTime().asSeconds() - elapsedTime;

    // If elapsed time is less than 5 seconds, keep moving in the same row
    if (deltaTime < 5.0f) {
        sf::Vector2f zombie = getPosition();
        setPosition(zombie.x - 1.0f, zombie.y);
    }
    else {
        // If elapsed time is 5 seconds or more, randomly switch rows
        int randomRow = rand() % 5; // Choose a random row index between 0 and 4
        const float verticalDistance = (1034 - 125) / 5.0f;
        float zombieY = 30 + randomRow * verticalDistance + verticalDistance / 2;
        setPosition(getPosition().x, zombieY);

        // Reset elapsed time and restart the clock
        elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

void FootballZombie::DeleteZombie()
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
bool FootballZombie::checkCollision(const sf::Vector2f& position) const
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
void FootballZombie::incrementHitCounter()
{
    hitCounter++;
    if (hitCounter == 6)
    {
        DeleteZombie();
        hitCounter = 0;
    }
}