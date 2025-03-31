/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
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
	Vecteur(size_t dimension = 3, float baseValue=0.0);
	
	~Vecteur();
	
	Vecteur(Vecteur &v);
	
	Vecteur &operator=(const Vecteur &vec);

	
	Vecteur operator+(const Vecteur &vec);


	float& operator[](size_t i);
	const float& operator[](size_t i) const;
	const float& get(size_t dim) const;
	//float &get(size_t dim);
	void set(size_t dim, float value);
	const size_t& dimensions() const;


private :
  // méthodes privées d'implémentation (si besoin)
};

// Prototypes des fonctions

void afficherVecteur(const Vecteur * v, std::ostream & out = std::cout);
Vecteur * lireVecteur(std::istream & in = std::cin);

std::ostream &operator<<(std::ostream &out, const Vecteur &vec);
std::istream &operator>>(std::istream &in, Vecteur &vec);

Vecteur add(const Vecteur *v1, const Vecteur *v2);
float operator*(const Vecteur &v1, const Vecteur &v2);
#endif
