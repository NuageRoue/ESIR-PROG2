#include "MathUtils.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <Environment.h>
#include <Renderer.h>
#include <time.h>
#include <Timer.h>

#include <Agent.h>
#include <Anthill.h>
#include <Food.h>
#include <vector>

static unsigned int windowWidth() { return 1024; }
static unsigned int windowHeight() { return 700; }

/// <summary>
/// called each time a key is pressed.
/// </summary>
/// <param name="key">The key.</param>
/// <param name="environment">The environment.</param>
void onKeyPressed(char key, Environment * environment)
{
	std::cout << "Key pressed: " << key << std::endl;

	switch (key)
	{
		case 'f':
			new Food(environment, environment->randomPosition(), MathUtils::random(200, 2000));
			break;
		case 'a':
			new Anthill(environment, environment->randomPosition());
			break;
		case 'd':
			std::vector<Food*> foods = environment->getAllInstancesOf<Food>();
			if (foods.size() > 0)
			{
				std::cout << "destroying a food. " << foods.size() -1 << " remaining" << std::endl;
				foods[MathUtils::random(0, foods.size()-1)]->setStatus(Agent::destroyStatus());
			}
			break;
	}

}

/// <summary>
/// Called at each time step.
/// </summary>
void onSimulate()
{
	Agent::simulate();
}

/// <summary>
/// The main program.
/// </summary>
/// <param name="argc">The number of arguments.</param>
/// <param name="argv">The arguments.</param>
/// <returns></returns>
int main(int /*argc*/, char ** /*argv*/)
{
	// 1 - Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS/* | SDL_INIT_AUDIO*/) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}
	// 2 - Initialization of the renderer
	Renderer::initialize(windowWidth(), windowHeight());

	// 3 - Creation of an environment
	Environment environment(windowWidth(), windowHeight());

	// 4 - We change the seed of the random number generator
	srand((unsigned int)time(NULL));

	// The main event loop...
	SDL_Event event;
	bool exit = false;

	Uint64 previousTicks = SDL_GetPerformanceCounter();
	const double frequency = static_cast<double>(SDL_GetPerformanceFrequency());

	while (!exit) 
	{
		// 1 - We handle events 
		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == 'q'))
			{
				::std::cout << "Exit signal detected" << ::std::endl;
				exit = true;
				break;
			}
			if (event.type == SDL_KEYDOWN)
			{
				onKeyPressed((char)event.key.keysym.sym, &environment);
			}
		}
		// 2 - We update the simulation
		
		Uint64 currentTicks = SDL_GetPerformanceCounter();
		double dt = static_cast<double>(currentTicks - previousTicks) / frequency;
		previousTicks = currentTicks;

		Timer::update(dt);
		onSimulate();
		// 3 - We render the scene
		Renderer::getInstance()->flush();
	}

	std::cout << "Shutting down renderer..." << std::endl;
	Renderer::finalize();
	
	std::cout << "Shutting down remaining agents..." << std::endl;
	Agent::finalize();

	std::cout << "Shutting down SDL" << std::endl;
	SDL_Quit();

	return 0;
}
