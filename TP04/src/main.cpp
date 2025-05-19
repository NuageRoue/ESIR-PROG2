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
#include <multiplicateur.h>
#include <operation_binaire.h>
#include <volume.h>
#include "signal_constant.h"

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
int
main()
{
  //q2_signal_constant();
  q4_harmonique();
  //q9_multiplicateur();
  //q10_multiplicateur();
  q12_volume();
  return 0;
}
