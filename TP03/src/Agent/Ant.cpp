#include "AntBasePheromone.h"
#include "Anthill.h"
#include "Pheromone.h"
#include "Vector2.h"
#include <Ant.h>
#include <cmath>
#include <iostream>
#include <Timer.h>
#include <iterator>

// Function to calculate the Euclidean distance between two points
float distance(Vector2<float> a, Vector2<float> b)
{
    return std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2));
}

// Constructor to initialize an ant with advanced behavior
Ant::Ant(Environment *env, Vector2<float> initialPos, Anthill* anthill)
    : AntBasePheromone(env, initialPos, anthill)
{
    // Initialization logic
}

// Method to update the behavior of the ant
void Ant::update()
{
    // Check if the ant's lifespan has expired
    if (checkLifeSpan())
        return;

    // Behavior when the ant is not carrying the maximum amount of food
    if (foodTransported < maxFood)
    {
        std::vector<Food*> foodPerceived = perceive<Food>(direction, perceptionAngle, perceptionDistance + getRadius());
        std::vector<Pheromone*> pheromonePerceived = perceive<Pheromone>(direction, perceptionAngle, pheromonePerceptionDistance + getRadius());

        if (!foodPerceived.empty())
        {
            // 1: If on food, collect it
            for (Food* food : foodPerceived)
            {
                float distance = getPosition().distance(food->getPosition());
                if (distance <= food->getRadius() + getRadius())
                {
                    GetFood(food);
                    break;
                }
            }

            // 2: If food is detected, head towards it
            if (foodTransported < maxFood)
            {
                orientToward(foodPerceived[MathUtils::random(0, foodPerceived.size() - 1)]->getPosition());
            }
            else
            {
                uTurn();
            }
        }
        else if (!pheromonePerceived.empty())
        {
            // 3: If pheromones are detected, head towards them
            Pheromone *chosenPheromone = choosePheromone();
            if (chosenPheromone != nullptr)
            {
                orientToward(chosenPheromone->getPosition());
            }
        }
        else
        {
            // 4: If no food or pheromones are detected, move randomly
            float updateAngle = MathUtils::random(-MathUtils::pi * Timer::dt(), MathUtils::pi * Timer::dt());
            rotate(updateAngle);
        }
    }

    // Behavior when the ant is carrying the maximum amount of food
    if (foodTransported == maxFood)
    {
        std::vector<Pheromone*> pheromonePerceived = perceive<Pheromone>(direction, perceptionAngle, pheromonePerceptionDistance + getRadius());
        std::vector<Anthill*> anthillPerceived = perceive<Anthill>();

        if (!anthillPerceived.empty())
        {
            for (Anthill* anthillDetected : anthillPerceived)
            {
                // 5: Deposit food at the anthill
                if (anthillDetected == anthill)
                {
                    anthill->depositFood(foodTransported);
                    foodTransported = 0;
                    uTurn();
                    break;
                }
            }
        }

        if (foodTransported > 0)
        {
            // 6.a: Return to the anthill following pheromones
            if (!pheromonePerceived.empty())
            {
                Pheromone *chosenPheromone = choosePheromone();
                if (chosenPheromone != nullptr && distance(anthill->getPosition(), chosenPheromone->getPosition()) < distance(getPosition(), anthill->getPosition()))
                {
                    orientToward(chosenPheromone->getPosition());
                }
                else
                {
                    orientToward(anthill->getPosition());
                }
            }
            else
            {
                // 6.b: Return directly to the anthill
                orientToward(anthill->getPosition());
            }
        }
    }

    // Move the ant and display it
    move();
    display();
}

