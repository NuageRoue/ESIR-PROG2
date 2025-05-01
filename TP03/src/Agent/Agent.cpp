#include <Agent.h>
#include <Environment.h>
#include <set>
#include <vector>

std::set<Agent*> Agent::agents;
Agent::Agent(Environment *env, Vector2<float> initialPos, float radius)
: Environment::LocalizedEntity(env, initialPos, radius), status(running)
{
	agents.insert(this);
}
	
const Agent::Status Agent::getStatus() const
{
	return status;
}

void Agent::setStatus(Agent::Status _status)
{
	status = _status;
}

void Agent::simulate()
{
	std::vector<Agent*> toDelete;
	for(Agent* agent : agents)
	{
		if (agent->status == running)
			agent->update();
		else if (agent->status == destroy)
			toDelete.push_back(agent);
	}

	for (Agent* agent : toDelete)
	{
		agents.erase(agent);
		delete agent;
	}
}

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

Agent::Status Agent::destroyStatus()
{
	return Agent::destroy;
}
