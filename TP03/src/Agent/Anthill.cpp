#include "Timer.h"
#include <Agent.h>
#include <Anthill.h>
#include <MathUtils.h>
#include <Renderer.h>
#include <SillyAnt.h>
#include <Ant.h>
#include <AntWithRule.h>
Anthill::Anthill(Environment *env, Vector2<float> pos)
: Agent(env, pos, 10), foodAmount(0)
{
	for (int i = 0; i < 50; i++)
	{
		new AntWithRule(getEnvironment(), getPosition(), this);
	}
}


void Anthill::depositFood(float quantity)
{
	foodAmount += quantity;
}


void Anthill::update()
{
	std::cout << "dt: " << Timer::dt() << std::endl;
	Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(0, 0, 255, 255)); // a termes, petite boucle pour separer rendering du calcul ?
	
}
