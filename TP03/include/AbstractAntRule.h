#ifndef ABSTRACTRULEANT
#define ABSTRACTRULEANT
#include <AbstractRule.h>

// Forward declaration of AntBasePheromone to avoid circular inclusion issues
class AntBasePheromone;

/// <summary>
/// An abstract class representing a rule specific to an ant with pheromone capabilities.
/// Inherits from AbstractRule and associates the rule with an ant.
/// </summary>
class AbstractAntRule : public AbstractRule
{
protected:
	/// <summary>
	/// A pointer to the ant associated with this rule.
	/// </summary>
	AntBasePheromone *ant;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="AbstractAntRule" /> class.
	/// </summary>
	/// <param name="ant">The ant associated with this rule.</param>
	AbstractAntRule(AntBasePheromone* ant);
};


#endif

