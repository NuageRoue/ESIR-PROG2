#include "AbstractRule.h"
#include "AntBasePheromone.h"
#include <AntWithRule.h>
#include <vector>
#include <Timer.h>

#include <MasterOrRule.h>
#include <OrRule.h>




void AntWithRule::PerceivePheromoneRule::action() 
{
	std::vector<Pheromone*> pheromonePerceived = ant->perceive<Pheromone>(ant->getDirection(), ant->getPerceptionAngle(), ant->pheromonePerceptionDistance + ant->getRadius());
	Pheromone *chosenPheromone = ant->choosePheromone();
	
	if (chosenPheromone != nullptr) 
	{
		ant->orientToward(chosenPheromone->getPosition());
	}
}

void AntWithRule::PerceiveFoodRule::action()
{
	std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());

	ant->orientToward(foodPerceived[MathUtils::random(0, foodPerceived.size() - 1)]->getPosition());
}


bool AntWithRule::PerceivePheromoneRule::condition() 
{
	std::vector<Pheromone*> pheromonePerceived = ant->perceive<Pheromone>(ant->getDirection(), ant->getPerceptionAngle(), ant->pheromonePerceptionDistance + ant->getRadius());
	return !pheromonePerceived.empty();
}

bool AntWithRule::PerceiveFoodRule::condition()
{
	std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());
	return !foodPerceived.empty();
}

void AntWithRule::OnFoodRule::action()
{
	std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());

	if (!foodPerceived.empty())
	{
		// 1: if on food: taking it;
		for (Food* food : foodPerceived)
		{
			float distance = ant->getPosition().distance(food->getPosition());
			if (distance <= food->getRadius() + ant->getRadius())
			{
				ant->GetFood(food);
				break;
			}
		}
		
		// 2: food detected: heading towards it;
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
bool AntWithRule::OnFoodRule::condition()
{

	std::vector<Food*> foodPerceived = ant->perceive<Food>(ant->getDirection(), ant->getPerceptionAngle(), ant->getPerceptionDistance() + ant->getRadius());
		
	if (!foodPerceived.empty())
	{
		// 1: if on food: taking it;
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


void AntWithRule::OnAnthillRule::action()
{
	std::vector<Anthill*> anthillPerceived = ant->perceive<Anthill>();

	if (!anthillPerceived.empty())
	{
		for (Anthill* anthillDetected : anthillPerceived)
		{
			// 5: depositing food
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

bool AntWithRule::OnAnthillRule::condition()
{
	std::vector<Anthill*> anthillPerceived = ant->perceive<Anthill>();

	if (!anthillPerceived.empty())
	{
		for (Anthill* anthillDetected : anthillPerceived)
		{
			// 5: depositing food
			if (anthillDetected == ant->getAnthill())
			{
				return true;
			}
		}
	}
	return false;
}

void AntWithRule::ErraticMovementRule::action()
{
	
	float updateAngle = MathUtils::random(	-MathUtils::pi * Timer::dt(),
						 MathUtils::pi * Timer::dt());
	ant->rotate(updateAngle);
}

bool AntWithRule::HasFoodRule::condition()
{
	return ant->getFoodTransported() == ant->maxFood;
}

bool AntWithRule::HasNoFoodRule::condition()
{
	return ant->getFoodTransported() < ant->maxFood;
}

	
AntWithRule::AntWithRule(Environment *env, Vector2<float> initialPos, Anthill* anthill)
: AntBasePheromone(env, initialPos, anthill), rule({new MasterOrRule(new HasFoodRule(this), new)})
{
	


}

void AntWithRule::update()
{
	if (checkLifeSpan())
		return;
	rule.action();
	move();
	display();
}
