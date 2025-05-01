#include <Agent.h>
#include <Food.h>
#include <MathUtils.h>
#include <Renderer.h>
#include <iostream>


Food::Food(Environment *env, Vector2<float> initialPos,float initialFoodAmount)
: Agent(env, initialPos, MathUtils::circleRadius(initialFoodAmount)), foodAmount(initialFoodAmount), oldFoodAmount(initialFoodAmount)
{
}

float Food::getFoodQuantity() const
{
	return foodAmount;
}

float Food::collectFood(float quantity)
{
	float toReturn = (quantity > foodAmount? foodAmount:quantity);
	std::cout << "food: trying to collect " << quantity << " with " << foodAmount << " available: " << toReturn << " taken." << std::endl;
	foodAmount -= toReturn;
	return toReturn;
}


void Food::update()
{
	if (foodAmount <= 0)
	{
		status = destroy;
		return;
	}

	if (oldFoodAmount != foodAmount)
	{
		oldFoodAmount = foodAmount;
		setRadius(MathUtils::circleRadius(foodAmount));
	}

	Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(154, 235, 38, 255)); // a termes, petite boucle pour separer rendering du calcul ?

	
}
