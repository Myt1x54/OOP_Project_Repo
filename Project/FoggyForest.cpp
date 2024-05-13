#include "FoggyForest.h"


FoggyForest::FoggyForest(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/FoggyForest.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
    font.loadFromFile("../Images/Comic_Sans.ttf"); // Load font file
    currencyText.setFont(font);
    currencyText.setCharacterSize(24);
    currencyText.setFillColor(sf::Color::White);
    currencyText.setPosition(356, 65); // position
    plant = new PlantFactory * [45];
}

void FoggyForest::draw()
{
    window.draw(backgroundSprite);
    window.draw(currencyText);
}

bool FoggyForest::loseLife()
{
    return 0;
}

int FoggyForest::display()
{
    sf::Vector2i mousePosition;

    int selectedPlantType = -1;

    bool shovel = false;

    for (int i = 0; i < 45; ++i)
    {
        plant[i] = nullptr;
    }

    int i = 0;
    while (window.isOpen())
    {

        /// Get the current mouse position relative to the window
        mousePosition = sf::Mouse::getPosition(window);

        draw();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Check if the player clicked on the plant icon
                    if (mousePosition.x >= 30 && mousePosition.x <= 130 && mousePosition.y >= 217 && mousePosition.y <= 329 && !shovel)
                    {
                        // Set the selected plant type based on the icon clicked
                        selectedPlantType = 1;
                    }
                    else if (mousePosition.x >= 30 && mousePosition.x <= 130 && mousePosition.y >= 355 && mousePosition.y <= 470 && !shovel)
                    {
                        // Set the selected plant type based on the icon clicked
                        selectedPlantType = 0;
                    }
                    else if (mousePosition.x >= 30 && mousePosition.x <= 130 && mousePosition.y >= 495 && mousePosition.y <= 605 && !shovel)
                    {
                        // Set the selected plant type based on the icon clicked
                        selectedPlantType = 2;
                    }
                    else if (mousePosition.x >= 30 && mousePosition.x <= 130 && mousePosition.y >= 630 && mousePosition.y <= 738 && !shovel)
                    {
                        // Set the selected plant type based on the icon clicked
                        selectedPlantType = 3;
                    }
                    else if (mousePosition.x >= 30 && mousePosition.x <= 130 && mousePosition.y >= 763 && mousePosition.y <= 882 && !shovel)
                    {
                        // Set the selected plant type based on the icon clicked
                        selectedPlantType = 4;
                    }
                    else if (mousePosition.x >= 30 && mousePosition.x <= 130 && mousePosition.y >= 908 && mousePosition.y <= 1023 && !shovel)
                    {
                        // Set the selected plant type based on the icon clicked
                        selectedPlantType = 5;
                    }
                    // Check if the player clicked on the grid
                    else
                    {
                        const float horizontalDistance = (1870 - 480) / 9.0f;
                        const float verticalDistance = (1034 - 125) / 5.0f;

                        // Calculate the row and column for the clicked position
                        int row = (event.mouseButton.y - 125) / verticalDistance;
                        int column = (event.mouseButton.x - 480) / horizontalDistance;

                        // Calculate the position of the new plant based on the row and column
                        float plantX = 420 + column * horizontalDistance + horizontalDistance / 2;
                        float plantY = 75 + row * verticalDistance + verticalDistance / 2;


                        if (mousePosition.x >= 30 && mousePosition.x <= 130 && mousePosition.y >= 25 && mousePosition.y <= 129)
                        {
                            // Set the selected plant type based on the icon clicked
                            if (shovel)
                            {
                                shovel = false;
                                selectedPlantType = -1;
                            }
                            else
                            {
                                shovel = true;
                                selectedPlantType = -1;
                            }
                        }
                        if (shovel)
                        {   // If shovel is selected
                            // Find the clicked plant and remove it
                            for (int j = 0; j < i; ++j)
                            {
                                if (plant[j] != nullptr && plant[j]->getPosition() == sf::Vector2f(plantX, plantY))
                                {
                                    delete plant[j]; // Delete the plant object

                                    // Shift the subsequent elements to fill the gap
                                    shovel = false;
                                    for (int k = j; k < i - 1; ++k)
                                    {
                                        plant[k] = plant[k + 1];
                                    }
                                    plant[i - 1] = nullptr;             // Set the last element to nullptr
                                    --i;                                // Decrease the plant count
                                    break;                              // Exit the loop after removing the plant
                                }
                            }
                        }

                        else if (selectedPlantType != -1 && i < 45 && !shovel)
                        {

                            bool insideGrid = false;

                            const float horizontalDistance = (1870 - 480) / 9.0f;
                            const float verticalDistance = (1034 - 125) / 5.0f;

                            // Check if the mouse click occurred inside the grid
                            if (event.mouseButton.x >= 480 && event.mouseButton.x <= 1870 &&
                                event.mouseButton.y >= 125 && event.mouseButton.y <= 1034) {
                                insideGrid = true;

                                // Calculate the row and column for the clicked position
                                int row = std::max(0, std::min(4, static_cast<int>((event.mouseButton.y - 125) / verticalDistance)));
                                int column = std::max(0, std::min(8, static_cast<int>((event.mouseButton.x - 480) / horizontalDistance)));

                                // Calculate the position of the new plant based on the row and column
                                float plantX = 420 + column * horizontalDistance + horizontalDistance / 2;
                                float plantY = 75 + row * verticalDistance + verticalDistance / 2;

                                // Now, proceed with plant placement logic here
                            }

                            bool positionOccupied = false;

                            for (int j = 0; j < i; ++j)
                            {
                                if (plant[j] != nullptr && plant[j]->getPosition() == sf::Vector2f(plantX, plantY))
                                {
                                    positionOccupied = true;
                                    break;
                                }
                            }

                            if (!positionOccupied && insideGrid)
                            {
                                switch (selectedPlantType)
                                {
                                case 0: // Peashooter
                                    plant[i] = new Peashooter(100, 125, 25, window);
                                    selectedPlantType = -1;
                                    break;
                                case 1: // Sunflower
                                    plant[i] = new Sunflower(100, 125, 25, window);
                                    selectedPlantType = -1;
                                    break;
                                case 2: // CherryBomb
                                    plant[i] = new CherryBomb(100, 125, 25, window);
                                    selectedPlantType = -1;
                                    break;
                                case 3: // WallNut
                                    plant[i] = new Wallnut(100, 125, 25, window, plantX, plantY);
                                    selectedPlantType = -1;
                                    break;
                                case 4: // SnowPeaShooter
                                    plant[i] = new SnowPea(100, 125, 25, window);
                                    selectedPlantType = -1;
                                    break;
                                case 5: // Repeater
                                    plant[i] = new Repeater(100, 125, 25, window);
                                    selectedPlantType = -1;
                                    break;

                                }
                                // Set position of new plant
                                plant[i]->setPosition(plantX, plantY);
                                i++;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 45; i++)
        {
            if (plant[i] != nullptr)
            {
                plant[i]->draw();
            }
        }
        window.display();

    }

    return -1; // Indicate no option selected
}

void FoggyForest::setCurrency(int value)
{
    currency = value;
    currencyText.setString("Currency: " + std::to_string(currency));
}

FoggyForest::~FoggyForest()
{
    // Deallocate memory for plant
    for (int i = 0; i < 45; ++i) {
        delete plant[i];
    }
    delete[] plant;
}