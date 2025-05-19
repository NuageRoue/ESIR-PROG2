#include <memory>
#include <volume_compose.h>
#include <multiplicateur.h>
#include <signal_constant.h>

volume_compose::volume_compose(double volume)
: filtre_compose(1,1)
{
	filtres.push_back(std::make_shared<multiplicateur>());
	producteurs.push_back(std::make_shared<signal_constant>(volume));
}

void volume_compose::setup()
{
	connecterEntreeInterne(0, 0, getEntree(0));
	connecterEntreeInterne(0, 1, getSortieInterneComposant(0, 0));

	connecterSortie(getSortieInterneFiltre(0, 0), 0);
}
