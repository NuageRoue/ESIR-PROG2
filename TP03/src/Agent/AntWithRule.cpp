#include "AbstractAntRule.h"
#include "AbstractRule.h"
#include "AntBasePheromone.h"
#include <AntWithRule.h>
#include <vector>
#include <Timer.h>

#include <MasterOrRule.h>
#include <OrRule.h>


// Constructor for PerceivePheromoneRule
AntWithRule::PerceivePheromoneRule::PerceivePheromoneRule(AntBasePheromone* ant)
    : AbstractAntRule(ant)
{
    // Initialization logic
}

// Action for PerceivePheromoneRule
void AntWithRule::PerceivePheromoneRule::action()
{
    std::vector<Pheromone*> pheromonePerceived = ant->perceive<Pheromone>(ant->getDirection(), ant->getPerceptionAngle(), ant->pheromonePerceptionDistance + ant->getRadius());
    Pheromone *chosenPheromone = ant->choosePheromone();

    if (chosenPheromone != nullptr)
    {
        ant->orientToward(chosenPheromone->getPosition());
    }
}

// Condition for PerceivePheromoneRule
bool AntWithRule::PerceivePheromoneRule::condition()
{
    std::vector<Pheromone*> pheromonePerceived = ant->perceive<Pheromone>(ant->getDirection(), ant->getPerceptionAngle(), ant->pheromonePerceptionDistance + ant->getRadius());
    return !pheromonePerceived.empty();
}

// Constructor for PerceiveFoodRule
AntWithRule::PerceiveFoodRule::PerceiveFoodRule(AntBasePheromone* ant)
    : AbstractAntRule(ant)
{
    // Initialization logic
}

// Action for PerceiveFoodRule
void AntWithRule::PerceiveFoodRule::action()
{
    std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());
    ant->orientToward(foodPerceived[MathUtils::random(0, foodPerceived.size() - 1)]->getPosition());
}

// Condition for PerceiveFoodRule
bool AntWithRule::PerceiveFoodRule::condition()
{
    std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());
    return !foodPerceived.empty();
}

// Constructor for OnFoodRule
AntWithRule::OnFoodRule::OnFoodRule(AntBasePheromone* ant)
    : AbstractAntRule(ant)
{
    // Initialization logic
}

// Action for OnFoodRule
void AntWithRule::OnFoodRule::action()
{
    std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());

    if (!foodPerceived.empty())
    {
        // Collect food if on it
        for (Food* food : foodPerceived)
        {
            float distance = ant->getPosition().distance(food->getPosition());
            if (distance <= food->getRadius() + ant->getRadius())
            {
                ant->GetFood(food);
                break;
            }
        }

        // Head towards food if not full
        if (ant->getFoodTransported() < ant->maxFood)
        {
            ant->orientToward(foodPerceived[MathUtils::random(0, foodPerceived.size() - 1)]->getPosition());
        }
        else
        {
            ant->uTurn();
        }
    }
}

// Condition for OnFoodRule
bool AntWithRule::OnFoodRule::condition()
{
    std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());

    if (!foodPerceived.empty())
    {
        for (Food* food : foodPerceived)
        {
            float distance = ant->getPosition().distance(food->getPosition());
            if (distance <= food->getRadius() + ant->getRadius())
            {
                return true;
            }
        }
    }
    return false;
}

// Constructor for OnAnthillRule
AntWithRule::OnAnthillRule::OnAnthillRule(AntBasePheromone* ant)
    : AbstractAntRule(ant)
{
    // Initialization logic
}

// Action for OnAnthillRule
void AntWithRule::OnAnthillRule::action()
{
    std::vector<Anthill*> anthillPerceived = ant->perceive<Anthill>();

    if (!anthillPerceived.empty())
    {
        for (Anthill* anthillDetected : anthillPerceived)
        {
            if (anthillDetected == ant->getAnthill())
            {
                ant->getAnthill()->depositFood(ant->getFoodTransported());
                ant->getFoodTransported() = 0;
                ant->uTurn();
                break;
            }
        }
    }
}

// Condition for OnAnthillRule
bool AntWithRule::OnAnthillRule::condition()
{
    std::vector<Anthill*> anthillPerceived = ant->perceive<Anthill>();

    if (!anthillPerceived.empty())
    {
        for (Anthill* anthillDetected : anthillPerceived)
        {
            if (anthillDetected == ant->getAnthill())
            {
                return true;
            }
        }
    }
    return false;
}

// Constructor for ErraticMovementRule
AntWithRule::ErraticMovementRule::ErraticMovementRule(AntBasePheromone* ant)
    : AbstractAntRule(ant)
{
    // Initialization logic
}

// Action for ErraticMovementRule
void AntWithRule::ErraticMovementRule::action()
{
    float updateAngle = MathUtils::random(-2 * MathUtils::pi * Timer::dt(), 2 * MathUtils::pi * Timer::dt());
    ant->rotate(updateAngle);
}

// Constructor for HasFoodRule
AntWithRule::HasFoodRule::HasFoodRule(AntBasePheromone* ant)
    : ErraticMovementRule(ant)
{
    // Initialization logic
}

// Condition for HasFoodRule
bool AntWithRule::HasFoodRule::condition()
{
    return ant->getFoodTransported() == ant->maxFood;
}

// Constructor for HasNoFoodRule
AntWithRule::HasNoFoodRule::HasNoFoodRule(AntBasePheromone* ant)
    : ErraticMovementRule(ant)
{
    // Initialization logic
}

// Condition for HasNoFoodRule
bool AntWithRule::HasNoFoodRule::condition()
{
    return ant->getFoodTransported() < ant->maxFood;
}

// Constructor for AntWithRule
AntWithRule::AntWithRule(Environment *env, Vector2<float> initialPos, Anthill* anthill)
    : AntBasePheromone(env, initialPos, anthill),
      rule({new MasterOrRule(new HasNoFoodRule(this), new OrRule({new OnFoodRule(this), new PerceiveFoodRule(this), new PerceivePheromoneRule(this)})),
            new MasterOrRule(new HasFoodRule(this), new OrRule({new OnAnthillRule(this), new PerceivePheromoneRule(this)}))})
{
    // Initialization logic
}

// Update method for AntWithRule
void AntWithRule::update()
{
    if (checkLifeSpan())
        return;
    rule.action();
    move();
    display();
}
