#ifndef ANTBASE
#define ANTBASE

#include <Vector2.h>
#include <Agent.h>
#include <Anthill.h>
#include <MathUtils.h>
#include <Food.h>


/// <summary>
/// Represents a base class for ants in the simulation environment.
/// Inherits from the Agent class and provides basic ant behavior and attributes.
/// </summary>
class AntBase : public Agent
{
protected:
	/// <summary>
	/// A pointer to the anthill this ant belongs to.
	/// </summary>
	Anthill* anthill;

	/// <summary>
	/// The lifespan of the ant.
	/// </summary>
	float life;

	/// <summary>
	/// The speed of the ant in cm/s.
	/// </summary>
	float speed;

	/// <summary>
	/// The direction vector of the ant's movement.
	/// </summary>
	Vector2<float> direction;

	/// <summary>
	/// The maximum amount of food the ant can transport.
	/// </summary>
	static constexpr float maxFood = 5;

	/// <summary>
	/// The amount of food currently transported by the ant.
	/// </summary>
	float foodTransported;

	/// <summary>
	/// The perception angle of the ant in radians (pi/2).
	/// </summary>
	float perceptionAngle;

	/// <summary>
	/// The perception distance of the ant in cm (3 cm).
	/// </summary>
	float perceptionDistance;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="AntBase" /> class.
	/// </summary>
	/// <param name="env">The environment in which the ant operates.</param>
	/// <param name="initialPos">The initial position of the ant.</param>
	/// <param name="anthill">The anthill the ant belongs to.</param>
	AntBase(Environment *env, Vector2<float> initialPos, Anthill* anthill);

	/// <summary>
	/// Moves the ant in its current direction.
	/// </summary>
	virtual void move();

	/// <summary>
	/// Rotates the ant by a specified angle.
	/// </summary>
	/// <param name="angle">The angle to rotate in radians.</param>
	void rotate(float angle);

	/// <summary>
	/// Makes the ant perform a U-turn.
	/// </summary>
	void uTurn();

	/// <summary>
	/// Orients the ant towards a target position.
	/// </summary>
	/// <param name="target">The target position to orient towards.</param>
	void orientToward(Vector2<float> target);

	/// <summary>
	/// Collects food from a perceived food entity.
	/// </summary>
	/// <param name="toPerceive">The food entity to collect from.</param>
	void GetFood(Food *toPerceive);

	/// <summary>
	/// Checks if the ant's lifespan has expired.
	/// </summary>
	/// <returns>True if the ant's life is over, otherwise false.</returns>
	bool checkLifeSpan();

	/// <summary>
	/// Displays the ant on the screen.
	/// </summary>
	void display();

	/// <summary>
	/// Gets the direction vector of the ant.
	/// </summary>
	/// <returns>The direction vector.</returns>
	const Vector2<float>& getDirection() const;

	/// <summary>
	/// Gets the perception angle of the ant.
	/// </summary>
	/// <returns>The perception angle in radians.</returns>
	float getPerceptionAngle() const;

	/// <summary>
	/// Gets the amount of food transported by the ant.
	/// </summary>
	/// <returns>The amount of food transported.</returns>
	float getFoodTransported() const;

	/// <summary>
	/// Gets the perception distance of the ant.
	/// </summary>
	/// <returns>The perception distance in cm.</returns>
	float getPerceptionDistance() const;

	/// <summary>
	/// Gets the anthill the ant belongs to (const version).
	/// </summary>
	/// <returns>The anthill pointer.</returns>
	const Anthill* getAnthill() const;

	/// <summary>
	/// Gets the anthill the ant belongs to (non-const version).
	/// </summary>
	/// <returns>The anthill pointer.</returns>
	Anthill* getAnthill();

	/// <summary>
	/// Gets a reference to the amount of food transported by the ant.
	/// </summary>
	/// <returns>A reference to the food transported.</returns>
	float& getFoodTransported();
};

#endif
