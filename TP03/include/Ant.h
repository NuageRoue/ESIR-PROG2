#ifndef ANT
#define ANT

#include "Anthill.h"
#include "Environment.h"
#include "Vector2.h"
#include <AntBasePheromone.h>

class Ant : public AntBasePheromone
{
	
private:

public:
	Ant(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	void update() override;
};


#endif
