#ifndef PRODUCTEUR_BASE
#define PRODUCTEUR_BASE

#include "flot.h"
#include <memory>
#include <producteur.h>
#include <vector>

class producteur_base : virtual public producteur
{

protected:
	virtual void connecterSortie(const std::shared_ptr<flot> & flot, unsigned int position);
	std::vector<std::shared_ptr<flot>> flots_sortie;
	int nbSortie;

public:

	producteur_base(int nbSortie);
	virtual ~producteur_base() = default;

	virtual unsigned int nbSorties() const;
	virtual const std::shared_ptr<flot> & getSortie(unsigned int numsortie) const;
};

#endif
