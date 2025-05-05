#include "Renderer.h"
#include "Vector2.h"
#include <Agent.h>
#include <AntBase.h>
#include <MathUtils.h>
#include <Timer.h>
#include <cmath>

// Constructor to initialize an ant with a given environment, position, and anthill
AntBase::AntBase(Environment *env, Vector2<float> initialPos, Anthill* anthill)
    : Agent(env, initialPos, 1),
      anthill(anthill),
      life(500000 /*MathUtils::random(1000, 2500)*/),
      speed(10),
      direction(0, 1),
      foodTransported(0),
      perceptionAngle(MathUtils::piDiv2),
      perceptionDistance(3 + getRadius())
{
    // Initialization logic
}

// Method to move the ant in its current direction
void AntBase::move()
{
    setPosition(getPosition() + direction * speed * Timer::dt());
}

// Method to rotate the ant by a specified angle
void AntBase::rotate(float angle)
{
    Vector2<float> oldDirection = direction;
    direction[0] = cos(angle) * direction[0] - sin(angle) * direction[1];
    direction[1] = sin(angle) * oldDirection[0] + cos(angle) * oldDirection[1];
}

// Method to make the ant perform a U-turn
void AntBase::uTurn()
{
    direction = direction * -1;
}

// Method to orient the ant towards a target position
void AntBase::orientToward(Vector2<float> target)
{
    float targetAngle = atan2(target[1] - getPosition()[1], target[0] - getPosition()[0]) - atan2(direction[1], direction[0]);

    if (targetAngle > MathUtils::pi)
        targetAngle -= 2 * MathUtils::pi;
    if (targetAngle < -MathUtils::pi)
        targetAngle += 2 * MathUtils::pi;

    rotate(targetAngle);
}

// Method to collect food from a perceived food entity
void AntBase::GetFood(Food *toPerceive)
{
    float foodAvailable = toPerceive->collectFood(maxFood - foodTransported);
    foodTransported += foodAvailable;
}

// Method to check if the ant's lifespan has expired
bool AntBase::checkLifeSpan()
{
    if (life <= 0)
    {
        status = destroy;
        return true;
    }
    // Updating life here
    life -= Timer::dt();
    return false;
}

// Method to display the ant on the screen
void AntBase::display()
{
    if (foodTransported > 0)
        Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(128, 255, 128, 255));
    else
        Renderer::getInstance()->drawCircle(getPosition(), getRadius(), Renderer::Color(255, 255, 255, 255));
}

// Method to get the direction vector of the ant
const Vector2<float>& AntBase::getDirection() const
{
    return direction;
}

// Method to get the perception angle of the ant
float AntBase::getPerceptionAngle() const
{
    return perceptionAngle;
}

// Method to get the amount of food transported by the ant
float AntBase::getFoodTransported() const
{
    return foodTransported;
}

// Method to get the perception distance of the ant
float AntBase::getPerceptionDistance() const
{
    return perceptionDistance;
}

// Method to get the anthill the ant belongs to (const version)
const Anthill* AntBase::getAnthill() const
{
    return anthill;
}

// Method to get the anthill the ant belongs to (non-const version)
Anthill* AntBase::getAnthill()
{
    return anthill;
}

// Method to get a reference to the amount of food transported by the ant
float& AntBase::getFoodTransported()
{
    return foodTransported;
}
