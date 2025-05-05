#ifndef SILLY
#define SILLY

#include "Environment.h"
#include "Vector2.h"
#include <AntBase.h>

/// <summary>
/// Represents a "silly" ant in the simulation environment.
/// Inherits from the AntBase class and implements a simple behavior of exploring the environment randomly.
/// </summary>
class SillyAnt : public AntBase
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="SillyAnt" /> class.
	/// </summary>
	/// <param name="env">The environment in which the ant operates.</param>
	/// <param name="initialPos">The initial position of the ant.</param>
	/// <param name="anthill">The anthill the ant belongs to.</param>
	SillyAnt(Environment *env, Vector2<float> initialPos, Anthill *anthill);

	/// <summary>
	/// Updates the behavior of the silly ant.
	/// The ant explores the environment randomly and collects food when perceived.
	/// </summary>
	void update() override;
};


#endif
