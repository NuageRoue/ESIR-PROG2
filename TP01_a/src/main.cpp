#include "vecteur.h"
#include <iostream>

/** \brief Programme principal */
int main()
{
  /** Insérez votre code ici... */
	Vecteur vecteur(4,2.0f);
	
	afficherVecteur(&vecteur);
	std::cout << "vecteur 1:\n";
	Vecteur * vec1 = new Vecteur(2,1); //lireVecteur();
	std::cout << "vecteur 2:\n";
	Vecteur * vec2 = new Vecteur(2,1);//lireVecteur();
	std::cout << "vecteur 3:\n";
	Vecteur * vec3 = new Vecteur(2,1);//lireVecteur();

	
	

	std::cout << "vecteur somme:\n";
	*vec3 = *vec3 + *vec1 + *vec2;
	std::cout << "vecteur affiché avec <<" << *vec3 << "\n";
	std::cin >> *vec3;
	std::cout << "vecteur créé avec >> puis affiché avec <<" << *vec3 << "\n";
	std::cout << (*vec3)[0] <<" et " << (*vec3)[1];
	(*vec3)[0] = 12	;

	delete(vec1);
	delete(vec2);
	delete(vec3);
	return 0;
}
