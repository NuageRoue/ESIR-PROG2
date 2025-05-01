#include "Renderer.h"
#include "Vector2.h"
#include <Agent.h>
#include <AntBase.h>
#include <MathUtils.h>
#include <Timer.h>
#include <cmath>

AntBase::AntBase(Environment *env, Vector2<float> initialPos, Anthill* anthill)
: Agent(env, initialPos, 1), anthill(anthill), life(500000/*MathUtils::random(1000, 2500)*/), speed(10),
  direction(0, 1), foodTransported(0), perceptionAngle(MathUtils::piDiv2), perceptionDistance(3 + getRadius())
{}


void AntBase::move()
{
	setPosition(getPosition() + direction * speed * Timer::dt());
}

void AntBase::rotate(float angle)
{
	Vector2<float> oldDirection = direction;
	direction[0] = cos(angle) * direction[0] - sin(angle) * direction[1];
	direction[1] = sin(angle) * oldDirection[0] + cos(angle) * oldDirection[1];
}

void AntBase::uTurn()
{
	direction = direction * -1;
}

void AntBase::orientToward(Vector2<float> target)
{
	float targetAngle =  atan2(target[1] - getPosition()[1], target[0] - getPosition()[0]) - atan2(direction[1], direction[0]);
	
	if (targetAngle > MathUtils::pi)
		targetAngle -= 2 * MathUtils::pi;
	if (targetAngle < -MathUtils::pi)
		targetAngle += 2 * MathUtils::pi;

	rotate(targetAngle);
}

void AntBase::GetFood(Food *toPerceive)
{
	float foodAvailable = toPerceive->collectFood(maxFood - foodTransported);

	foodTransported += foodAvailable;
}

bool AntBase::checkLifeSpan()
{
	if (life <= 0)
	{
		status = destroy;
		return true;
	}
	// updating life here;
	life -= Timer::dt();
	return false;
}

void AntBase::display()
{
	if (foodTransported > 0)
		Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(128, 255, 128, 255));
	else
		Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(255, 255, 255, 255));
}


const Vector2<float>& AntBase::getDirection() const
{
	return direction;
}

float AntBase::getPerceptionAngle() const
{
	return perceptionAngle;
}

float AntBase::getFoodTransported() const
{
	return foodTransported;
}

float AntBase::getPerceptionDistance() const
{
	return perceptionDistance;
}

const Anthill* AntBase::getAnthill() const
{
	return anthill;
}


Anthill* AntBase::getAnthill()
{
	return anthill;
}

float &AntBase::getFoodTransported()
{
	return foodTransported;
}
