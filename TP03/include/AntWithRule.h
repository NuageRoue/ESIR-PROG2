#ifndef ANTWITHRULE
#define ANTWITHRULE

#include "AbstractAntRule.h"
#include "AntBasePheromone.h"
#include <OrRule.h>
class AntWithRule : AntBasePheromone
{
private:
	friend class PerceivePheromoneRule;
	friend class PerceiveFood;
	friend class OnFoodRule;
	friend class OnAnthillRule;

	class PerceivePheromoneRule : public AbstractAntRule
	{
	public:
		PerceivePheromoneRule(AntBasePheromone*ant);
		void action() override;
		bool condition() override;
	};
	class PerceiveFoodRule : public AbstractAntRule
	{
	public:
		PerceiveFoodRule(AntBasePheromone*ant);

		void action() override;
		bool condition() override;
	};

	class OnFoodRule : public AbstractAntRule
	{
	public:
		OnFoodRule(AntBasePheromone*ant);

		void action() override;
		bool condition() override;
	};

	class OnAnthillRule : public AbstractAntRule
	{
	public:
		OnAnthillRule(AntBasePheromone*ant);

		void action() override;
		bool condition() override;
	};
	
	class ErraticMovementRule : public AbstractAntRule
	{
	public:
		ErraticMovementRule(AntBasePheromone*ant);

		void action() override;
	};

	class HasFoodRule : public ErraticMovementRule
	{
	public:
		HasFoodRule(AntBasePheromone*ant);

		bool condition() override;
	};


	class HasNoFoodRule : public ErraticMovementRule
	{
	public:
		HasNoFoodRule(AntBasePheromone*ant);

		bool condition() override;
	};

	OrRule rule;
	

public:
	AntWithRule(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	void update() override;
	
};

#endif
