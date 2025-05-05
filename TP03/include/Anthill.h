#ifndef ANTHILL
#define ANTHILL

#include <Agent.h>


/// <summary>
/// Represents an anthill in the simulation environment.
/// Inherits from the Agent class and serves as a base for ants.
/// </summary>
class Anthill : public Agent
{
private:
	/// <summary>
	/// The amount of food stored in the anthill.
	/// </summary>
	float foodAmount;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Anthill" /> class.
	/// </summary>
	/// <param name="env">The environment in which the anthill is placed.</param>
	/// <param name="pos">The position of the anthill.</param>
	Anthill(Environment *env, Vector2<float> pos);

	/// <summary>
	/// Deposits a specified amount of food into the anthill.
	/// </summary>
	/// <param name="quantity">The amount of food to deposit.</param>
	void depositFood(float quantity);

	/// <summary>
	/// Updates the state of the anthill.
	/// Draws the anthill as a circle on the screen.
	/// </summary>
	void update() override;
};

#endif
