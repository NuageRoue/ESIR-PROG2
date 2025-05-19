#include <cassert>
#include <filtre_compose.h>
#include <iostream>
#include <ostream>

filtre_compose::filtre_compose(int nbEntrees, int nbSorties)
: filtre_base(nbEntrees, nbSorties)
{
	
}


void filtre_compose::connecterEntreeInterne(int filterID, int entryID, const std::shared_ptr<flot> & flot)
{
	assert(filterID < filtres.size());

	filtres[filterID]->connecterEntree(flot, entryID);
}

const std::shared_ptr<flot> & filtre_compose::getSortieInterneFiltre(int filterID, int entryID)
{
	assert(filterID < filtres.size());

	return filtres[filterID]->getSortie(entryID);
}

const std::shared_ptr<flot> & filtre_compose::getSortieInterneComposant(int composantID, int entryID)
{
	assert(composantID < filtres.size());

	return producteurs[composantID]->getSortie(entryID);
}


void filtre_compose::calculer()
{
	for (int i = 0; i < producteurs.size(); i++)
	{
		producteurs[i]->calculer();
	}

	for (int i = 0; i < filtres.size(); i++)
	{
		//std::cout << "i = " << i << "; ";
		filtres[i]->calculer();
      		//std::cout << std::endl;
	}

	//std::cout << "done" << std::endl;

}
