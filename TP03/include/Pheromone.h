#ifndef PHEROMONE
#define PHEROMONE

#include "Vector2.h"
#include <Agent.h>
#include <Environment.h>

class Pheromone : public Agent
{
private:
	float pheromoneAmount;
public:

	Pheromone(Environment *env, Vector2<float> position, float pheromoneAmount);

	float getQuantity() const;

	void addQuantity(float q);

	void update() override;
};

#endif
