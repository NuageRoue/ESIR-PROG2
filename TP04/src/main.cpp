/*
 * main.cpp
 *
 *  Created on: 8 mars 2013
 *      Author: engel
 */

#include "constantes.h"
#include <functional>
#include "enregistreur_fichier.h"
#include "enregistreur_fichier_texte.h"
#include "harmonique.h"
#include <iostream>
#include <multiplicateur.h>
#include <operation_binaire.h>
#include <volume.h>
#include <volume_compose.h>
#include "signal_constant.h"
#include <mixeur.h>
#include <lecteur_fichier.h>
#include <exceptions.h>

/*
void
q2_signal_constant()
{
  signal_constant constant(0.5);
  enregistreur_fichier_texte enregistreur("02_constant.txt", 1);
  enregistreur.connecterEntree(constant.getSortie(0), 0);
  // générer des valeurs
  for (unsigned int i = 0; i < 50; ++i) {
    constant.calculer();
    enregistreur.calculer();
  }
}
*/

void
q4_harmonique()
{
  harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
  enregistreur_fichier enregistreur("04_harmonique.raw", 1);	// fichier mono
  enregistreur.connecterEntree(la440.getSortie(0), 0);
  // produire 2 secondes de son
  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
    la440.calculer();
    enregistreur.calculer();
  }
}

void
q9_multiplicateur()
{
  harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
  harmonique la880(880); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
  multiplicateur mult;

  mult.connecterEntree(la440.getSortie(0), 0);
  mult.connecterEntree(la880.getSortie(0), 1);

  enregistreur_fichier enregistreur("09_multiplicateur.raw", 1);	// fichier mono
  enregistreur.connecterEntree(mult.getSortie(0), 0);
  // produire 2 secondes de son
  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
    la440.calculer();
    la880.calculer();
    mult.calculer();
    enregistreur.calculer();
  }
}
void
q10_multiplicateur()
{
  harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
  harmonique la880(880); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
  operation_binaire<std::multiplies<double>> mult;

  mult.connecterEntree(la440.getSortie(0), 0);
  mult.connecterEntree(la880.getSortie(0), 1);

  enregistreur_fichier enregistreur("10_operation_binaire.raw", 1);	// fichier mono
  enregistreur.connecterEntree(mult.getSortie(0), 0);
  // produire 2 secondes de son
  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
    la440.calculer();
    la880.calculer();
    mult.calculer();
    enregistreur.calculer();
  }
}

void
q12_volume()
{
  harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
  volume volume(.1);
  volume.connecterEntree(la440.getSortie(0), 0);
  volume.setup();
  enregistreur_fichier enregistreur("12_volume.raw", 1);	// fichier mono
  enregistreur.connecterEntree(volume.getSortie(0), 0);
  // produire 2 secondes de son
  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
    la440.calculer();
    volume.calculer();
    enregistreur.calculer();
  }
  
}
void
q14_volume_compose()
{
  harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
  volume_compose volume(.1);
  volume.connecterEntree(la440.getSortie(0), 0);
  volume.setup();
  enregistreur_fichier enregistreur("14_volume_compose.raw", 1);	// fichier mono
  enregistreur.connecterEntree(volume.getSortie(0), 0);
  // produire 2 secondes de son
  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
    la440.calculer();
    volume.calculer();
    enregistreur.calculer();
  }
  
}

void q17_mixage()
{
	//lecteur_fichier mono("raw/mono.raw", 1);
	lecteur_fichier stereo("raw/stereo.raw", 2);

	mixeur mix({4, 1});
	mix.connecterEntree(stereo.getSortie(0), 0);
	mix.connecterEntree(stereo.getSortie(1), 1);
	//mix.connecterEntree(mono.getSortie(0), 2);

	mix.setup();

  	enregistreur_fichier enregistreur("17_mix.raw", 1);	// fichier mono
  	enregistreur.connecterEntree(mix.getSortie(0), 0);
  	//enregistreur.connecterEntree(stereo.getSortie(1), 0);
	try 
	{
		while (true) 
		{
			//mono.calculer();
			stereo.calculer();

			mix.calculer();
			enregistreur.calculer();

		}
	}
	catch (const fin_de_fichier_exception& e) 
	{
		std::cout << "Lecture terminée : " << e.what() << std::endl;
	}
	catch (const composant_exception& e) 
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
}

int
main()
{
  //q2_signal_constant();
  //q4_harmonique();
  //q9_multiplicateur();
  //q10_multiplicateur();
  //q12_volume();
  //q14_volume_compose();
  q17_mixage();
  return 0;
}
