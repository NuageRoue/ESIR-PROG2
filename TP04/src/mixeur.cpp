#include <iostream>
#include <iterator>
#include <memory>
#include <mixeur.h>
#include <ostream>
#include <vector>
#include <volume_compose.h>
#include <functional>
#include <operation_binaire.h>

mixeur::mixeur(std::vector<double> volumes)
: filtre_compose(volumes.size(), 1)
{
	for (int i = 0; i < volumes.size(); i++) 
	{
		filtres.push_back(std::make_shared<volume_compose>(volumes[i]));
	}
	
	for (int i = 0; i < volumes.size() - 1; i++) 
	{
		filtres.push_back(std::make_shared<operation_binaire<std::plus<double>>>());
	}
}

void mixeur::setup()
{
	std::cout << "there is " << nbEntrees() << std::endl;
	for (int i = 0; i < nbEntrees(); i++)
	{
		std::cout << i << " to " << i << std::endl;
		connecterEntreeInterne(i, 0, getEntree(i));
		std::dynamic_pointer_cast<filtre_compose>(filtres[i])->setup();
	}
	
	std::cout << nbEntrees() << ":" << "0" << " to " << "0" << std::endl;
	std::cout << nbEntrees() << ":" << "1" << " to " << "1" << std::endl;
	connecterEntreeInterne(nbEntrees(), 0, getSortieInterneFiltre(0, 0));
	connecterEntreeInterne(nbEntrees(), 1, getSortieInterneFiltre(1, 0));

	for (int j = nbEntrees() + 1; j < nbEntrees() * 2 - 1; j++)
	{
		std::cout << j << ":" << "0" << " to " << j + 1 - nbEntrees() << std::endl;
		std::cout << j << ":" << "1" << " to " << j - 1 << std::endl;
		connecterEntreeInterne(j, 0, getSortieInterneFiltre(j+1 - nbEntrees(),0));
		connecterEntreeInterne(j, 1, getSortieInterneFiltre(j - 1,0));
	}

	connecterSortie(getSortieInterneFiltre(nbEntrees() * 2 - 2, 0), 0);
}
