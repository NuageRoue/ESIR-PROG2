#include <lecteur_fichier.h>
#include <composant_exception.h>
#include <exceptions.h>

lecteur_fichier::lecteur_fichier(const std::string& nom_fichier, int canaux)
: producteur_base(canaux), nb_canaux(canaux)
{
	if (canaux != 1 && canaux != 2) 
	{
		throw composant_exception("lecteur_fichier : nombre de canaux invalide (doit être 1 ou 2)");
	}

	fichier.open(nom_fichier.c_str(), std::ios::in | std::ios::binary);
	if (!fichier.good()) 
	{
		throw fichier_introuvable_exception("Impossible d'ouvrir le fichier : " + nom_fichier);
	}
}

lecteur_fichier::~lecteur_fichier() 
{
        fichier.close();
}

void lecteur_fichier::calculer()
{
	for (int canal = 0; canal < nb_canaux; ++canal) 
	{
		char buffer[2];
		fichier.read(buffer, 2);

		if (fichier.eof())
			throw fin_de_fichier_exception("Fin du fichier atteinte.");


		if (!fichier.good())
			throw lecture_fichier_exception("Erreur lors de la lecture du fichier.");

		short ech = 	static_cast<unsigned char>(buffer[0]) |
				(static_cast<unsigned char>(buffer[1]) << 8);

		double ech_normalise = static_cast<double>(ech) / 32768.0; // normalisation par la plus grande valeur possible

		flots_sortie[canal]->inserer(ech_normalise);
	}
}
