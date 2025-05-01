#ifndef ANT_PHEROMONE
#define ANT_PHEROMONE

#include "Anthill.h"
#include "Environment.h"
#include "Vector2.h"
#include <AntBase.h>
#include <Pheromone.h>

class AntBasePheromone : public AntBase
{
protected:
	static constexpr float pheromoneAmount_withFood = 100;
	static constexpr float pheromoneAmount_withoutFood = 10;
public:
	static constexpr float pheromonePerceptionDistance = 8;
	AntBasePheromone(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	void putPheromone(float q);

	void move() override;

	Pheromone *choosePheromone();

};

#endif
