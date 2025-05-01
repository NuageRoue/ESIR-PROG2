#include "AntBasePheromone.h"
#include "Anthill.h"
#include "Pheromone.h"
#include "Vector2.h"
#include <Ant.h>
#include <cmath>
#include <iostream>
#include <Timer.h>
#include <iterator>

float distance(Vector2<float> a, Vector2<float> b)
{
	return std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2));
}

Ant::Ant(Environment *env, Vector2<float> initialPos, Anthill* anthill)
: AntBasePheromone(env, initialPos, anthill)
{}


void Ant::update()
{
	if (checkLifeSpan())
		return;

	if (foodTransported < maxFood) // 1, 2, 3 and 4
	{
		std::vector<Food*> foodPerceived = perceive<Food>(direction, perceptionAngle, perceptionDistance + getRadius());
		std::vector<Pheromone*> pheromonePerceived = perceive<Pheromone>(direction, perceptionAngle, pheromonePerceptionDistance + getRadius());
		
		if (!foodPerceived.empty())
		{
			// 1: if on food: taking it;
			for (Food* food : foodPerceived)
			{
				float distance = getPosition().distance(food->getPosition());
				if (distance <= food->getRadius() + getRadius())
				{
					GetFood(food);
					break;
				}
			}
			
			// 2: food detected: heading towards it;
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
			// 3: pheromone detected: heading towards it;
			Pheromone *chosenPheromone = choosePheromone();
	
			if (chosenPheromone != nullptr) 
			{
				orientToward(chosenPheromone->getPosition());
			}
		}
		else 
		{
			// 4: pheromone and food undetected: random angle;

			float updateAngle = MathUtils::random(	-MathUtils::pi * Timer::dt(),
								MathUtils::pi * Timer::dt());
			rotate(updateAngle);
		}

	}
	
	if (foodTransported == maxFood)// 5 and 6 : going back to the anthill 
	{
		
		std::vector<Pheromone*> pheromonePerceived = perceive<Pheromone>(direction, perceptionAngle, pheromonePerceptionDistance + getRadius()); 
		std::vector<Anthill*> anthillPerceived = perceive<Anthill>();

		if (!anthillPerceived.empty())
		{
			for (Anthill* anthillDetected : anthillPerceived)
			{
				// 5: depositing food
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
			// 6.a: going back to anthill following pheromones;
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
				// 6.b : going directly to the anthill;
				orientToward(anthill->getPosition());
			}
		}
	}

	move();
	display();
}
