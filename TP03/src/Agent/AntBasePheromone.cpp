#include "MathUtils.h"
#include <Pheromone.h>
#include <AntBase.h>
#include <AntBasePheromone.h>
#include <vector>


AntBasePheromone::AntBasePheromone(Environment *env, Vector2<float> initialPos, Anthill* anthill)
: AntBase(env, initialPos, anthill)
{}

void AntBasePheromone::putPheromone(float q)
{
	std::vector<Pheromone*> pheromones = perceive<Pheromone>();

	if (pheromones.empty())
	{
		// create a new pheromone with q amount;
		new Pheromone(getEnvironment(), getPosition(), q);
	}
	else 
	{
		for (Pheromone* pheromone : pheromones)
		{
			pheromone->addQuantity(q);
		}
	}
}

void AntBasePheromone::move()
{
	AntBase::move();

	if (foodTransported > 0)
		putPheromone(pheromoneAmount_withFood);
	else
		putPheromone(pheromoneAmount_withoutFood);
}

Pheromone *AntBasePheromone::choosePheromone()
{
	std::vector<Pheromone*> pheromones = perceive<Pheromone>(direction, perceptionAngle, pheromonePerceptionDistance + getRadius());
	if (pheromones.empty())
		return nullptr;

	std::vector<float> weights;
	for (Pheromone* pheromone : pheromones)
	{
		weights.push_back(pheromone->getQuantity());
	}
	
	return pheromones[MathUtils::randomChoose(weights)];
}
