#include <multiplicateur.h>
#include <cassert>

multiplicateur::multiplicateur()
: filtre_base(2, 1)
{}

void multiplicateur::calculer()
{
	//getEntree(0); // entree 0
	//getEntree(1); // entree 1
	
	assert(yaDesEchantillons());

	double value;
	value = getEntree(0)->extraire() * getEntree(1)->extraire();
	
	getSortie(0)->inserer(value);


}
