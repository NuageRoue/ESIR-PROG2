#include "vecteur.h"
#include <iostream>
#include <ostream>

/** \brief Programme principal */

int main()
{
  /** Insérez votre code ici... */
	std::cout << "definition vecteur d'entiers a 3 coordonnees:" << std::endl;
	Vecteur<int> vecInt(3);
	std::cin >> vecInt;	
	
	std::cout << "definition vecteur de float a 3 coordonnees:" << std::endl;
	Vecteur<float> vecFloat(3);
	std::cin >> vecFloat;

	std::cout << "produit scalaire vecInt * vecFloat: " << vecInt * vecFloat << std::endl;
	std::cout << "produit scalaire vecFloat * vecInt: " << vecFloat * vecInt << std::endl;

	std::cout << "somme de vecFloat et vecInt: " << (vecFloat + vecInt) << std::endl;
	std::cout << "somme de vecInt et vecInt: " << (vecInt + vecInt) << std::endl;
	std::cout << "somme de vecInt et vecFloat: " << (vecInt + vecFloat) << std::endl;

	Vecteur<std::string> test(3, "test");
	std::cout << "somme de str et str" << (test + test) << std::endl;

	// copie 
	Vecteur<int> vecTest(vecFloat);
	Vecteur<int> vecTest1(vecInt);

	
}
