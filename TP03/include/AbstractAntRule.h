#ifndef ABSTRACTRULEANT
#define ABSTRACTRULEANT
#include <AbstractRule.h>

class AntBasePheromone;  // déclaration anticipée de la classe pour éviter les soucis d'inclusion circulaire
//#include <AntBasePheromone.h>
class AbstractAntRule : public AbstractRule
{

protected:
	AntBasePheromone *ant;

public:
	AbstractAntRule(AntBasePheromone* ant);

};

#endif

