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
    static sf::Clock clock;
    static float elapsedTime = 0.0f;

    float deltaTime = clock.getElapsedTime().asSeconds() - elapsedTime;

    if (deltaTime < 2.0f) 
    {
        sf::Vector2f zombie = getPosition();
        setPosition(zombie.x - 1.0f, zombie.y);
    }
    else 
    {
        int randomRow = rand() % 5; 
        const float verticalDistance = (1034 - 125) / 5.0f;
        float zombieY = 30 + randomRow * verticalDistance + verticalDistance / 2;
        setPosition(getPosition().x, zombieY);

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

    // Generate a new position
    do 
    {
        randomRow = rand() % 5; // Choose a random row index between 0 and 4
        const float verticalDistance = (1034 - 125) / 5.0f;
        zombieY = 30 + randomRow * verticalDistance + verticalDistance / 2;
    } while (abs(zombieY - prevY) < 100.0f); // Ensure sufficient difference in Y position

    zombieSprite.setPosition(1900 + (rand() + 900) % 1500, zombieY);

    // Update previous position variables
    prevX = zombieSprite.getPosition().x;
    prevY = zombieY;
}

bool FootballZombie::checkCollision(const sf::Vector2f& position) const
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
void FootballZombie::incrementHitCounter()
{
    hitCounter++;
    if (hitCounter == 6)
    {
        DeleteZombie();
        hitCounter = 0;
    }
}