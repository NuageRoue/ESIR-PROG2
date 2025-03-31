#include "vecteur.h"
#include <iostream>
#include <ostream>

/** \brief Programme principal */

int main()
{
	std::cout << "Saisie d'un vecteur int\n";
	Vecteur<int> * v10_ptr = lireVecteur<int>();
Vecteur<int> v10 = *v10_ptr;

  delete(v10_ptr);
}
