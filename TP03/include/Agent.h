#ifndef AGENT
#define AGENT

#include <Environment.h>
#include <Vector2.h>
#include <set>

/// <summary>
/// Represents an agent in the simulation environment.
/// An agent is a localized entity with specific behavior.
/// </summary>
class Agent : public Environment::LocalizedEntity
{
private:
	/// <summary>
	/// A set containing all agents created during the simulation.
	/// </summary>
	static std::set<Agent*> agents;

protected:
	/// <summary>
	/// Enumeration representing the status of an agent.
	/// </summary>
	typedef enum { running, destroy } Status;

	/// <summary>
	/// The current status of the agent.
	/// </summary>
	Status status;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Agent" /> class.
	/// </summary>
	/// <param name="env">The environment in which the agent operates.</param>
	/// <param name="initialPos">The initial position of the agent.</param>
	/// <param name="radius">The radius of the agent. Default is the default radius of LocalizedEntity.</param>
	Agent(Environment *env, Vector2<float> initialPos, float radius = Environment::LocalizedEntity::defaultRadius());

	/// <summary>
	/// Virtual destructor for the agent.
	/// </summary>
	virtual ~Agent() = default;

	/// <summary>
	/// Updates the behavior of the agent.
	/// This method should be overridden by derived classes to implement specific behavior.
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// Gets the current status of the agent.
	/// </summary>
	/// <returns>The status of the agent.</returns>
	const Status getStatus() const;

	/// <summary>
	/// Sets the status of the agent.
	/// </summary>
	/// <param name="_status">The new status to set.</param>
	void setStatus(Status _status);

	/// <summary>
	/// Simulates the behavior of all agents.
	/// Calls the update method for each agent that is running.
	/// Deletes agents that are marked for destruction.
	/// </summary>
	static void simulate();

	/// <summary>
	/// Finalizes the simulation by deleting all remaining agents.
	/// </summary>
	static void finalize();

	/// <summary>
	/// Returns the status value representing a destroyed agent.
	/// </summary>
	/// <returns>The destroy status.</returns>
	static Status destroyStatus();
};


#endif
