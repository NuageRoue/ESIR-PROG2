#ifndef LECTEUR_FICHIER
#define LECTEUR_FICHIER

#include <fstream>
#include <vector>
#include <memory>
#include "producteur_base.h"

class lecteur_fichier : public producteur_base {
private:
	std::ifstream fichier;
	int nb_canaux;

public:
	lecteur_fichier(const std::string& nom_fichier, int canaux);
	~lecteur_fichier();
	void calculer() override;

};

#endif
