#ifndef ABSTRACTRULEANT
#define ABSTRACTRULEANT
#include <AbstractRule.h>
#include <AntBasePheromone.h>
class AbstractAntRule : public AbstractRule
{

protected:
	AntBasePheromone *ant;

public:
	AbstractAntRule(AntBasePheromone* ant);

};

#endif

