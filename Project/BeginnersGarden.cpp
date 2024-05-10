#include<iostream>
#include "BeginnersGarden.h"
using namespace std;


BeginnersGarden::BeginnersGarden(RenderWindow& window) : Levels(window)
{
    // Load background image for BeginnersGarden
    backgroundimage.loadFromFile("../Images/BeginnersGarden.png");
    backgroundTexture.loadFromImage(backgroundimage);
    backgroundSprite.setTexture(backgroundTexture);
    plant = new PlantFactory*[45];
}

void BeginnersGarden::draw()
{
    window.draw(backgroundSprite);
}

int BeginnersGarden::display()
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

        // Handle events specific to BeginnersGarden
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
                                    // Add cases for other plant types
                                }
                                // Set the position of the new plant
                                plant[i]->setPosition(plantX, plantY);
                                i++;
                            }
                        }
                    }
                }
            }
        }
        if (shovel)
        {
            window.setMouseCursorVisible(false);
            sf::Texture mouseTexture;
            sf::Sprite mouseSprite;
            mouseTexture.loadFromFile("../Images/Shovel2.png");
            mouseSprite.setTexture(mouseTexture);


            mouseSprite.setPosition(mousePosition.x - 90, mousePosition.y - 90);
            
           
            window.draw(mouseSprite);
        }
        else if (selectedPlantType == 0)                // Peashooter
        { 
            window.setMouseCursorVisible(false);
            sf::Texture mouseTexture;
            sf::Sprite mouseSprite;
            mouseTexture.loadFromFile("../Images/PeaShooterSprite.png");
            mouseSprite.setTexture(mouseTexture);

            mouseSprite.setPosition(mousePosition.x - 40, mousePosition.y - 80);
            window.draw(mouseSprite);
        }
            
        else if (selectedPlantType == 1)                // Sunflower
        {
            window.setMouseCursorVisible(false);        
            sf::Texture mouseTexture;
            sf::Sprite mouseSprite;
            mouseTexture.loadFromFile("../Images/SunflowerSprite.png");
            mouseSprite.setTexture(mouseTexture);

            mouseSprite.setPosition(mousePosition.x - 70, mousePosition.y - 80);
            window.draw(mouseSprite);
        }
        else
        {
            window.setMouseCursorVisible(true);
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

BeginnersGarden::~BeginnersGarden()
{
    // Deallocate memory for plant
    for (int i = 0; i < 45; ++i) 
    {
        delete plant[i];
    }
    delete[] plant;
}
                