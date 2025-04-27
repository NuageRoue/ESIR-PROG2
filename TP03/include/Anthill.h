#ifndef ANTHILL
#define ANTHILL

#include <Agent.h>


class Anthill : public Agent
{
private:
	float foodAmount;
public:
	Anthill(Environment *env, Vector2<float> pos);

	void depositFood(float quantity);

	void update() override;
};

#endif
