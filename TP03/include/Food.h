#ifndef FOOD
#define FOOD

#include <Agent.h>


class Food : public Agent
{
private:
	float foodAmount;

	float oldFoodAmount;

public:
	Food(Environment *env, Vector2<float> initialPos,float initialFoodAmount);

	float getFoodQuantity() const;
	float collectFood(float quantity);

	void update() override;
};
#endif
