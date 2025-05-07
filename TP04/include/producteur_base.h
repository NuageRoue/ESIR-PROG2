#ifndef PRODUCTEUR_BASE
#define PRODUCTEUR_BASE

#include "flot.h"
#include <memory>
#include <producteur.h>
#include <vector>

class producteur_base : public producteur
{

protected:
	virtual void connecterSortie(std::shared_ptr<flot> flot, int position);
	std::vector<std::shared_ptr<flot>> flots;

public:

	virtual ~producteur_base() = default;

	virtual unsigned int nbSorties() const;
	virtual const std::shared_ptr<flot> & getSortie(unsigned int numsortie) const;

};

#endif
