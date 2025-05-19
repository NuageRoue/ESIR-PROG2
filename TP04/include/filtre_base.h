#ifndef FILTRE_BASE
#define FILTRE_BASE

#include <filtre.h>
#include <producteur_base.h>
#include <consommateur_base.h>


class filtre_base : public filtre, public producteur_base, public consommateur_base
{

public:
	filtre_base(int nbEntrees, int nbSorties);

	virtual ~filtre_base() = default;

};

#endif
