/** @brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/


/**
 * @brief
 * @param nom 
 * @return 
 * @warning
 */

#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <iostream>


// Déclaration de la classe vecteur
class Vecteur {
private :
	// attributs
	size_t dimension;
	float *values;


public :
  	// prototypes des constructeurs et autres méthodes publiques
	

	/**
 	* @brief constructeur de la classe vecteur
 	* @param dimension : dimension du vecteur
 	* @param baseValue : valeur de chaque coordonnée du vecteur. par défaut, 0
 	*/
	Vecteur(size_t dimension = 3, float baseValue=0.0);
	
	/**
	* @brief destructeur de la classe
	*/
	~Vecteur();
	
	/**
	* @brief constructeur par copie
	*/
	Vecteur(Vecteur &v);
	
	/**
	* @brief opérateur d'affectation de la classe
	* @param vec : vecteur dont on souhaite récupérer les valeurs
	* @return Vecteur ayant comme paramètres une copie de ceux de vec
	*/
	Vecteur &operator=(const Vecteur &vec);

	/**
	* @brief somme de vecteurs
	*/
	Vecteur operator+(const Vecteur &vec);


	/**
	* @brief accès aux éléments du vecteur
	*/
	float& operator[](size_t i);
	/**
	* @brief accès aux éléments du vecteur
	*/
	const float& operator[](size_t i) const;
	/**
	* @brief accès aux éléments du vecteur
	*/
	const float& get(size_t dim) const;
	//float &get(size_t dim);
	/**
	* @brief setter des éléments du vecteur
	*/
	void set(size_t dim, float value);

	/**
	* @brief getter de la dimension du vecteur
	*/
	const size_t& dimensions() const;


private :
  // méthodes privées d'implémentation (si besoin)
	// pas besoin :)
};

// Prototypes des fonctions

/**
 * @brief afficher un vecteur sur un ostream
 * @param v : le vecteur (pointeur sur vecteur) à afficher
 * @param out : le flux de sortie où afficher le vecteur, par défaut, std::cout (le flux de sortie de base)
 */
void afficherVecteur(const Vecteur * v, std::ostream & out = std::cout);
/**
 * @brief lire un vecteur depuis un flux d'entrée 
 * @param in : le flux d'entrée où lire le vecteur, par défaut, std::cin (le flux d'entrée de base)
 */
Vecteur * lireVecteur(std::istream & in = std::cin);

/**
 * @brief opérateur pour afficher un vecteur sur un ostream
 * @param out : le flux de sortie où afficher le vecteur
 * @param vec : le vecteur (pointeur sur vecteur) à afficher
 * @return le flux
 */
std::ostream &operator<<(std::ostream &out, const Vecteur &vec);
/**
 * @brief opérateur pour lire un vecteur sur un istream
 * @param out : le flux de sortie où lire le vecteur
 * @param vec : le vecteur dans lequel stocker la lecture
 * @return le flux
 * @warning le vecteur vec doit déjà avoir une dimension
 */
std::istream &operator>>(std::istream &in, Vecteur &vec);

/**
 * @brief somme de deux vecteurs 
 * @param v1 : le vecteur 1
 * @param vec : le vecteur 2
 * @return le vecteur dont les coordonnees sont une somme des coordonnées des 2 autres
 */
Vecteur add(const Vecteur *v1, const Vecteur *v2);
/**
 * @brief produit scalaire de deux vecteurs 
 * @param v1 : le vecteur 1
 * @param vec : le vecteur 2
 * @return le resultat du produit scalaire des 2 vecteurs
 */
float operator*(const Vecteur &v1, const Vecteur &v2);
#endif
