#include <Agent.h>
#include <Environment.h>
#include <set>
#include <vector>

// Definition of the static member to keep track of all agents
std::set<Agent*> Agent::agents;

// Constructor to initialize an agent with a given environment, position, and radius
Agent::Agent(Environment *env, Vector2<float> initialPos, float radius)
    : Environment::LocalizedEntity(env, initialPos, radius), status(running)
{
    // Add the newly created agent to the set of all agents
    agents.insert(this);
}

// Method to get the current status of the agent
const Agent::Status Agent::getStatus() const
{
    return status;
}

// Method to set the status of the agent
void Agent::setStatus(Agent::Status _status)
{
    status = _status;
}

// Static method to simulate the behavior of all agents
void Agent::simulate()
{
    std::vector<Agent*> toDelete;
    // Iterate over all agents
    for (Agent* agent : agents)
    {
        if (agent->status == running)
            agent->update(); // Update running agents
        else if (agent->status == destroy)
            toDelete.push_back(agent); // Mark agents for deletion
    }

    // Delete agents marked for destruction
    for (Agent* agent : toDelete)
    {
        agents.erase(agent);
        delete agent;
    }
}

// Static method to finalize the simulation by deleting all agents
void Agent::finalize()
{
    while (!agents.empty())
    {
        auto it = agents.begin();
        Agent* agent = *it;
        agents.erase(it);
        delete agent;
    }
}

// Static method to return the destroy status
Agent::Status Agent::destroyStatus()
{
    return Agent::destroy;
}