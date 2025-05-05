#ifndef ANT_PHEROMONE
#define ANT_PHEROMONE

#include "AbstractAntRule.h"
#include "Anthill.h"
#include "Environment.h"
#include "Vector2.h"
#include <AntBase.h>
#include <Pheromone.h>
#include <vector>

/// <summary>
/// Represents an ant with pheromone-based behavior in the simulation environment.
/// Inherits from the AntBase class and adds functionality for depositing and perceiving pheromones.
/// </summary>
class AntBasePheromone : public AntBase
{
protected:
	/// <summary>
	/// The amount of pheromone deposited when the ant is carrying food.
	/// </summary>
	static constexpr float pheromoneAmount_withFood = 100;

	/// <summary>
	/// The amount of pheromone deposited when the ant is not carrying food.
	/// </summary>
	static constexpr float pheromoneAmount_withoutFood = 10;


public:
	/// <summary>
	/// The maximum distance at which the ant can perceive pheromones.
	/// </summary>
	static constexpr float pheromonePerceptionDistance = 8;

	/// <summary>
	/// Initializes a new instance of the <see cref="AntBasePheromone" /> class.
	/// </summary>
	/// <param name="env">The environment in which the ant operates.</param>
	/// <param name="initialPos">The initial position of the ant.</param>
	/// <param name="anthill">The anthill the ant belongs to.</param>
	AntBasePheromone(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	/// <summary>
	/// Deposits a specified amount of pheromone at the ant's current position.
	/// </summary>
	/// <param name="q">The amount of pheromone to deposit.</param>
	void putPheromone(float q);

	/// <summary>
	/// Moves the ant and deposits pheromones based on whether it is carrying food.
	/// </summary>
	void move() override;

	/// <summary>
	/// Chooses a pheromone to follow based on perceived pheromones.
	/// </summary>
	/// <returns>A pointer to the chosen pheromone, or nullptr if no pheromones are perceived.</returns>
	Pheromone* choosePheromone();

};


#endif
