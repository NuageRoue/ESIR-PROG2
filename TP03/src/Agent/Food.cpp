#include <Agent.h>
#include <Food.h>
#include <MathUtils.h>
#include <Renderer.h>
#include <iostream>


// Constructor to initialize a food entity with a given environment, position, and initial food amount
Food::Food(Environment *env, Vector2<float> initialPos, float initialFoodAmount)
    : Agent(env, initialPos, MathUtils::circleRadius(initialFoodAmount)),
      foodAmount(initialFoodAmount),
      oldFoodAmount(initialFoodAmount)
{
    // Initialization logic
}

// Method to get the current quantity of food available
float Food::getFoodQuantity() const
{
    return foodAmount;
}

// Method to collect a specified amount of food
float Food::collectFood(float quantity)
{
    // Determine the amount of food to return, limited by the available food
    float toReturn = (quantity > foodAmount ? foodAmount : quantity);
    std::cout << "food: trying to collect " << quantity << " with " << foodAmount << " available: " << toReturn << " taken." << std::endl;
    foodAmount -= toReturn; // Decrease the food amount by the collected quantity
    return toReturn;
}

// Method to update the state of the food entity
void Food::update()
{
    // If no food is left, mark the entity for destruction
    if (foodAmount <= 0)
    {
        status = destroy;
        return;
    }

    // If the food amount has changed, update the radius
    if (oldFoodAmount != foodAmount)
    {
        oldFoodAmount = foodAmount;
        setRadius(MathUtils::circleRadius(foodAmount));
    }

    // Draw the food as a circle on the screen
    Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(154, 235, 38, 255));
}
