#include <consommateur_base.h>
#include <memory>
#include <cassert>
#include <imp_flot.h>

std::vector<std::shared_ptr<flot>> flots;

consommateur_base::consommateur_base(int nbSortie)
: nbSortie(nbSortie), flots(nbSortie, std::make_shared<imp_flot>())
{}

void consommateur_base::connecterEntree(const std::shared_ptr<flot> & flot, unsigned int position)
{
	assert(position < nbEntrees());
	flots[position] = flot;
}

unsigned int consommateur_base::nbEntrees() const
{
	return nbSortie;
}

const std::shared_ptr<flot> & consommateur_base::getEntree(unsigned int numsortie) const
{
	assert(numsortie < nbEntrees());

	return flots[numsortie];
}
