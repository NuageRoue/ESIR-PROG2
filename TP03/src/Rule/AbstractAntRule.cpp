#include "AntBasePheromone.h"
#include <AbstractAntRule.h>

AbstractAntRule::AbstractAntRule(AntBasePheromone *ant)
: ant(ant)
{
	ant->AddRule(this);
}
