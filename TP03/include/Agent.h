#ifndef AGENT
#define AGENT

#include <Environment.h>
#include <Vector2.h>
#include <set>

class Agent : public Environment::LocalizedEntity
{
private: // pour l'instant meme si a mon avis protected est plus logique ?
	static std::set<Agent*> agents; 
protected:
	// question 3.3
	typedef enum{ running, destroy } Status ;
	
	Status status; // par defaut, Status.running; 
public:

	// question 3.1
	Agent(Environment *env, Vector2<float> initialPos, float radius=Environment::LocalizedEntity::defaultRadius());
	
	// question 3.2 : si la classe doit servir de base a d'autres methodes, doit etre abstract ? mais c'est pas clair;
	virtual void update() = 0;

	const Status getStatus() const;

	void setStatus(Status _status);

	static void simulate();

	static void finalize();

	static Status destroyStatus();

};

#endif
