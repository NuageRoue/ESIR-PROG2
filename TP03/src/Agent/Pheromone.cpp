#include "Agent.h"
#include "Renderer.h"
#include "Timer.h"
#include <Pheromone.h>
#include <algorithm>



Pheromone::Pheromone(Environment *env, Vector2<float> position, float pheromoneAmount)
: Agent(env, position), pheromoneAmount(pheromoneAmount)
{}

float Pheromone::getQuantity() const
{
	return pheromoneAmount;
}

void Pheromone::addQuantity(float q)
{
	pheromoneAmount+=q;
}

void Pheromone::update() 
{
	if (pheromoneAmount < 0.01f)
	{	
		status = destroy;
		return;
	}
	pheromoneAmount -= 0.01 * Timer::dt();
	std::cout << "pheromone" << std::endl;	
	Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(0, 128, 128, std::min(getQuantity(), 255.0f)));
}
