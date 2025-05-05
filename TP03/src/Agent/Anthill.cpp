#include "Timer.h"
#include <Agent.h>
#include <Anthill.h>
#include <MathUtils.h>
#include <Renderer.h>
#include <SillyAnt.h>
#include <Ant.h>
#include <AntWithRule.h>

// Constructor to initialize an anthill with a given environment and position
Anthill::Anthill(Environment *env, Vector2<float> pos)
    : Agent(env, pos, 10), foodAmount(0)
{
    // Create 50 ants associated with this anthill
    for (int i = 0; i < 50; i++)
    {
        new AntWithRule(getEnvironment(), getPosition(), this);
    }
}

// Method to deposit a specified amount of food into the anthill
void Anthill::depositFood(float quantity)
{
    foodAmount += quantity; // Increase the food amount by the deposited quantity
}

// Method to update the state of the anthill
void Anthill::update()
{
    // Output the time elapsed since the last update
    std::cout << "dt: " << Timer::dt() << std::endl;

    // Draw the anthill as a circle on the screen
    Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(0, 0, 255, 255));
}
