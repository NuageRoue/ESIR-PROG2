#ifndef ANT
#define ANT

#include <Vector2.h>
#include <Agent.h>
#include <Anthill.h>
#include <MathUtils.h>
#include <Food.h>


class AntBase : public Agent
{
protected:
	Anthill* anthill;
	float life;

	float speed; // 1cm.s^-1
	Vector2<float> direction;

	static constexpr float maxFood = 5;
	float foodTransported;

	float perceptionAngle; // pi/2
	float perceptionDistance; // 3cm
public:
	AntBase(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	//void update() override;

	virtual void move();
	void rotate(float angle);
	void uTurn();
	void orientToward(Vector2<float> target);

	void GetFood(Food *toPerceive);
	bool checkLifeSpan();
	void display();
};

#endif
