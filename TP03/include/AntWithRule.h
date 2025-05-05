#ifndef ANTWITHRULE
#define ANTWITHRULE

#include "AbstractAntRule.h"
#include "AntBasePheromone.h"
#include <OrRule.h>
/// <summary>
/// Represents an ant that operates based on a set of rules.
/// Inherits from AntBasePheromone and uses rule-based behavior to determine actions.
/// </summary>
class AntWithRule : public AntBasePheromone
{
private:
	// Friend classes for accessing private members
	friend class PerceivePheromoneRule;
	friend class PerceiveFoodRule;
	friend class OnFoodRule;
	friend class OnAnthillRule;

	/// <summary>
	/// Rule for perceiving pheromones.
	/// </summary>
	class PerceivePheromoneRule : public AbstractAntRule
	{
	public:
		PerceivePheromoneRule(AntBasePheromone* ant);
		void action() override;
		bool condition() override;
	};

	/// <summary>
	/// Rule for perceiving food.
	/// </summary>
	class PerceiveFoodRule : public AbstractAntRule
	{
	public:
		PerceiveFoodRule(AntBasePheromone* ant);
		void action() override;
		bool condition() override;
	};

	/// <summary>
	/// Rule for actions when the ant is on food.
	/// </summary>
	class OnFoodRule : public AbstractAntRule
	{
	public:
		OnFoodRule(AntBasePheromone* ant);
		void action() override;
		bool condition() override;
	};

	/// <summary>
	/// Rule for actions when the ant is on the anthill.
	/// </summary>
	class OnAnthillRule : public AbstractAntRule
	{
	public:
		OnAnthillRule(AntBasePheromone* ant);
		void action() override;
		bool condition() override;
	};

	/// <summary>
	/// Rule for erratic movement.
	/// </summary>
	class ErraticMovementRule : public AbstractAntRule
	{
	public:
		ErraticMovementRule(AntBasePheromone* ant);
		void action() override;
	};

	/// <summary>
	/// Rule for actions when the ant has food.
	/// </summary>
	class HasFoodRule : public ErraticMovementRule
	{
	public:
		HasFoodRule(AntBasePheromone* ant);
		bool condition() override;
	};

	/// <summary>
	/// Rule for actions when the ant has no food.
	/// </summary>
	class HasNoFoodRule : public ErraticMovementRule
	{
	public:
		HasNoFoodRule(AntBasePheromone* ant);
		bool condition() override;
	};

	/// <summary>
	/// The rule set governing the ant's behavior.
	/// </summary>
	OrRule rule;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="AntWithRule" /> class.
	/// </summary>
	/// <param name="env">The environment in which the ant operates.</param>
	/// <param name="initialPos">The initial position of the ant.</param>
	/// <param name="anthill">The anthill the ant belongs to.</param>
	AntWithRule(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	/// <summary>
	/// Updates the behavior of the ant based on its rules.
	/// </summary>
	void update() override;
};


#endif
