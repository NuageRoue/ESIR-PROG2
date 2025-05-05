#include "Environment.h"
#include "MathUtils.h"
#include "Vector2.h"
#include <SillyAnt.h>
#include <iostream>
#include <vector>
#include <Timer.h>

// Constructor to initialize a silly ant with a given environment, position, and anthill
SillyAnt::SillyAnt(Environment *env, Vector2<float> initialPos, Anthill *anthill)
    : AntBase(env, initialPos, anthill)
{
    // Rotate to a random initial direction
    rotate(MathUtils::random(-MathUtils::pi, MathUtils::pi));
}

// Method to update the behavior of the silly ant
void SillyAnt::update()
{
    // Check if the ant's lifespan has expired
    if (checkLifeSpan())
        return;

    // Perceive food in the environment
    std::vector<Food*> foodPerceived = perceive<Food>(direction, perceptionAngle, perceptionDistance + getRadius());

    // If the ant is carrying the maximum amount of food, head back to the anthill
    if (foodTransported == maxFood)
    {
        std::cout << "silly ant: heading home" << std::endl;
    }
    // If food is perceived, orient towards it
    else if (foodPerceived.size() > 0)
    {
        std::cout << "silly ant: food located: heading towards it." << std::endl;
        orientToward(foodPerceived[MathUtils::random(0, foodPerceived.size() - 1)]->getPosition());
    }
    // Otherwise, rotate randomly to explore
    else
    {
        float updateAngle = MathUtils::random(-MathUtils::pi / 10 * Timer::dt(), MathUtils::pi / 10 * Timer::dt());
        rotate(updateAngle);
    }

    // Move the ant in its current direction
    move();

    // If the ant is carrying food, check if it has reached the anthill to deposit it
    if (foodTransported > 0)
    {
        for (Anthill* anthillDetected : perceive<Anthill>())
        {
            if (anthillDetected == anthill)
            {
                std::cout << "silly ant: back to anthill: deposing food." << std::endl;
                anthill->depositFood(foodTransported);
                foodTransported = 0;
            }
        }
    }
    // If the ant is not carrying the maximum amount of food, try to collect food if nearby
    else if (foodTransported < maxFood)
    {
        for (Food* food : foodPerceived)
        {
            float distance = getPosition().distance(food->getPosition());
            if (distance <= food->getRadius() + getRadius())
            {
                std::cout << "silly ant: on food: recolting" << std::endl;
                GetFood(food);
                if (foodTransported == maxFood)
                    orientToward(anthill->getPosition());
                break;
            }
        }
    }

    // Display the ant on the screen
    display();
}
