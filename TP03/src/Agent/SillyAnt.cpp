#include "Environment.h"
#include "MathUtils.h"
#include "Vector2.h"
#include <SillyAnt.h>
#include <iostream>
#include <vector>
#include <Timer.h>

SillyAnt::SillyAnt(Environment *env, Vector2<float> initialPos, Anthill *anthill)
: AntBase(env, initialPos, anthill)
{
	rotate(MathUtils::random(-MathUtils::pi, MathUtils::pi));
}

void SillyAnt::update()
{
	if (checkLifeSpan())
		return;


	std::vector<Food*> foodPerceived = perceive<Food>(direction, perceptionAngle, perceptionDistance + getRadius());
	if (foodTransported == maxFood)
	{
		//going back home
		std::cout << "silly ant: heading home" << std::endl;
	}
	else if (foodPerceived.size() > 0)
	{
		std::cout << "silly ant: food located: heading towards it." << std::endl;
		// going toward the food;
		orientToward(foodPerceived[MathUtils::random(0, foodPerceived.size() - 1)]->getPosition());
	}
	else 
	{
		float updateAngle = MathUtils::random(	-MathUtils::pi/10 * Timer::dt(),
							MathUtils::pi/10 * Timer::dt());
		rotate(updateAngle);
	}

	move();
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
	display();
}
