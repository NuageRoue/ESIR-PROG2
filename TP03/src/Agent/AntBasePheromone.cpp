#include "AbstractAntRule.h"
#include "MathUtils.h"
#include <Pheromone.h>
#include <AntBase.h>
#include <AntBasePheromone.h>
#include <vector>


// Constructor to initialize an ant with pheromone capabilities
AntBasePheromone::AntBasePheromone(Environment *env, Vector2<float> initialPos, Anthill* anthill)
    : AntBase(env, initialPos, anthill)
{
    // Initialization logic
}

// Method to deposit a specified amount of pheromone at the ant's current position
void AntBasePheromone::putPheromone(float q)
{
    std::vector<Pheromone*> pheromones = perceive<Pheromone>();

    if (pheromones.empty())
    {
        // Create a new pheromone with the specified amount
        new Pheromone(getEnvironment(), getPosition(), q);
    }
    else
    {
        // Add the pheromone quantity to existing pheromones
        for (Pheromone* pheromone : pheromones)
        {
            pheromone->addQuantity(q);
        }
    }
}

// Method to move the ant and deposit pheromones based on its food transport status
void AntBasePheromone::move()
{
    AntBase::move(); // Move the ant using the base class method

    // Deposit pheromones based on whether the ant is carrying food
    if (foodTransported > 0)
        putPheromone(pheromoneAmount_withFood);
    else
        putPheromone(pheromoneAmount_withoutFood);
}

// Method to choose a pheromone to follow based on perceived pheromones
Pheromone* AntBasePheromone::choosePheromone()
{
    std::vector<Pheromone*> pheromones = perceive<Pheromone>(direction, perceptionAngle, pheromonePerceptionDistance + getRadius());
    if (pheromones.empty())
        return nullptr;

    std::vector<float> weights;
    for (Pheromone* pheromone : pheromones)
    {
        weights.push_back(pheromone->getQuantity());
    }

    // Choose a pheromone based on its quantity
    return pheromones[MathUtils::randomChoose(weights)];
}


