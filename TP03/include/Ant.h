#ifndef ANT
#define ANT

#include "Anthill.h"
#include "Environment.h"
#include "Vector2.h"
#include <AntBasePheromone.h>

/// <summary>
/// Represents an ant with advanced behavior in the simulation environment.
/// Inherits from AntBasePheromone and implements complex behavior based on pheromones and food perception.
/// </summary>
class Ant : public AntBasePheromone
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Ant" /> class.
	/// </summary>
	/// <param name="env">The environment in which the ant operates.</param>
	/// <param name="initialPos">The initial position of the ant.</param>
	/// <param name="anthill">The anthill the ant belongs to.</param>
	Ant(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	/// <summary>
	/// Updates the behavior of the ant.
	/// The ant collects food, follows pheromones, and returns to the anthill based on its state.
	/// </summary>
	void update() override;
};

/// <summary>
/// Calculates the Euclidean distance between two points.
/// </summary>
/// <param name="a">The first point.</param>
/// <param name="b">The second point.</param>
/// <returns>The distance between the two points.</returns>
float distance(Vector2<float> a, Vector2<float> b);



#endif
