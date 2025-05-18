#include <memory>
#include <producteur_base.h>
#include <cassert>
#include <imp_flot.h>

std::vector<std::shared_ptr<flot>> flots;

producteur_base::producteur_base(int nbSortie)
: nbSortie(nbSortie), flots(nbSortie, std::make_shared<imp_flot>())
{}

void producteur_base::connecterSortie(std::shared_ptr<flot> & flot, unsigned int position)
{
	assert(position < nbSorties());
	flots[position] = flot;
}

unsigned int producteur_base::nbSorties() const
{
	return nbSortie;
}

const std::shared_ptr<flot> & producteur_base::getSortie(unsigned int numsortie) const
{
	assert(numsortie < nbSorties());

	return flots[numsortie];
}
