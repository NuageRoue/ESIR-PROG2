#ifndef FILTRE_COMPOSE
#define FILTRE_COMPOSE

#include "filtre.h"
#include <filtre_base.h>
#include <vector>
#include <memory>

class filtre_compose : public filtre_base
{
protected:

	filtre_compose(int nbEntree, int nbSortie);

	std::vector<std::shared_ptr<producteur>> producteurs;
	std::vector<std::shared_ptr<filtre>> filtres;

	void connecterEntreeInterne(int filterID, int entryID, const std::shared_ptr<flot> & flot);
	const std::shared_ptr<flot> & getSortieInterneFiltre(int filterID, int entryID);
	const std::shared_ptr<flot> & getSortieInterneComposant(int composantID, int entryID);



public:
	virtual void setup() = 0;
	void calculer();



};

#endif
