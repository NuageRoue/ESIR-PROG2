#ifndef FOOD
#define FOOD

#include <Agent.h>


/// <summary>
/// Represents a food entity in the simulation environment.
/// Inherits from the Agent class and models food that can be collected by ants.
/// </summary>
class Food : public Agent
{
private:
	/// <summary>
	/// The current amount of food available.
	/// </summary>
	float foodAmount;

	/// <summary>
	/// The previous amount of food, used to detect changes in food quantity.
	/// </summary>
	float oldFoodAmount;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Food" /> class.
	/// </summary>
	/// <param name="env">The environment in which the food is placed.</param>
	/// <param name="initialPos">The initial position of the food.</param>
	/// <param name="initialFoodAmount">The initial amount of food available.</param>
	Food(Environment *env, Vector2<float> initialPos, float initialFoodAmount);

	/// <summary>
	/// Gets the current quantity of food available.
	/// </summary>
	/// <returns>The amount of food available.</returns>
	float getFoodQuantity() const;

	/// <summary>
	/// Collects a specified amount of food.
	/// </summary>
	/// <param name="quantity">The amount of food to collect.</param>
	/// <returns>The amount of food actually collected.</returns>
	float collectFood(float quantity);

	/// <summary>
	/// Updates the state of the food entity.
	/// Checks if the food amount has changed and updates the radius accordingly.
	/// Draws the food as a circle on the screen.
	/// </summary>
	void update() override;
};

#endif
