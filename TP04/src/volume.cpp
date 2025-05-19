#include "volume.h"

volume::volume(double volume)
: filtre_base(1, 1), vol(volume), mult()
{
}

void volume::calculer()
{
	vol.calculer();
	mult.calculer();
}

void volume::setup()
{
	mult.connecterEntree(getEntree(0), 0);
	mult.connecterEntree(vol.getSortie(0), 1);

	connecterSortie(mult.getSortie(0), 0);
}
