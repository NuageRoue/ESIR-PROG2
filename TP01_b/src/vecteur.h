/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/

#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <cstddef>
#include <iostream>
#include <ostream>
#include <cassert>
#include <string>
using namespace std;

template <class T>
class Vecteur {
private :
	// attributs
	size_t dimension;
	T *values;


public :
  	// prototypes des constructeurs et autres méthodes publiques
	//Vecteur(size_t dimension = 3, T baseValue = T());
	
	/**
	 * @brief constructeur par défaut de la classe. explicit pour éviter les appels implicites (duh)
	 * @param dim : dimension du vecteur (3 par défaut)
	 * @param values : valeur de base des coordonnées du vecteur, par défaut celle du constructeur par défaut du type T
	 */
	explicit Vecteur(size_t dim=3, T baseValue=T()) : dimension(dim), values(new T[dim])
	{
		assert(dimension > 0);
		for (size_t i = 0; i < dimension; i++)
			values[i] = baseValue;
		std::cout << "construction d'un vecteur à " << dim << " dimensions, de valeur initiale " << baseValue << std::endl;
	}

	~Vecteur()
	{
		delete[] values;
	}
	
	/**
	 * @brief constructeur par copie de la classe. 
	 * @param v : vecteur dont le type peut être autre que celui de base
	 */
	template <class U>
	Vecteur(Vecteur<U> &v): dimension(v.dimensions()), values(new T[v.dimensions()])
	{
		for (size_t i = 0; i < dimension; i++)
        		values[i] = static_cast<T>(v.get(i));
	}
	Vecteur(Vecteur &v): dimension(v.dimensions()), values(new T[v.dimensions()])
	{
		for (size_t i = 0; i < dimension; i++)
        		values[i] = (v.get(i));
	}

	/* operators */

	
	/**
	 * @brief opérateur d'affectation
	 */
	Vecteur &operator=(const Vecteur &vec)
	{
		if (this != &vec)
		{
			if (values != nullptr) delete[] values; // si on référence déjà quelque chose, on le delete avant
			values = new T[vec.dimensions()];
			dimension = vec.dimensions();
			for (size_t i = 0; i < dimension; i++)
        			values[i] = static_cast<T>(vec.get(i));
		}
		return *this;
	}
	
	/**
	 * @brief opérateur de somme de la mort
	 * @param vec : vecteur à sommer au vecteur courant : le type peut être tout autre
	 * @return : un vecteur dont le type dépend de u et v s'ils sont sommables
	 */
	template <class U>
	auto operator+(const Vecteur<U> &vec)
	{
		assert(dimensions() == vec.dimensions());
		//assert((std::is_arithmetic<T>::value && std::is_arithmetic<U>::value)); // inutile : je voulais gérer le cas où on ferait une somme de Vecteur<std::string> et de Vecteur<int> (par exemple), mais c'était trop long et complexe pour rien, donc un petit assert pour empecher ça, mais au final le type de retour common_type empêche complètement de faire une telle somme, et une telle assertion empêche de concaténer des vecteurs de chaines (quel que puisse être l'intérêt d'un vecteur de chaine de caractères :/
		Vecteur<std::common_type_t<T, U>> toReturn(vec.dimensions()); 
		for (size_t i = 0; i < dimensions(); i++)
			toReturn.set(i, get(i) + vec.get(i));
		return toReturn;
	}
	
	T& operator[](size_t i)
	{
		return (T &)get(i);
	}

	const T& operator[](size_t i) const
	{
		return get(i);	
	}


	const T& get(size_t dim) const
	{
		assert(dim < dimension);
		return (const T&)values[dim];
	}
	
	void set(size_t dim, T value)
	{
		assert(dim < dimension);
		values[dim] = value;
	}
	
	const size_t& dimensions() const
	{
		return dimension;
	}


private :

  // méthodes privées d'implémentation (si besoin)
};

template <class T>
std::ostream &operator<<(std::ostream &out, const Vecteur<T> &vec)
{
	out << "vecteur: ";
	for (size_t i = 0; i < vec.dimensions(); i++)
		out << vec.get(i) << ";";
	return out;
}

template <class T>
std::istream &operator>>(std::istream &in, Vecteur<T> &vec)
{
	T value;
	for (size_t i = 0; i < vec.dimensions(); i++)
	{
		in >> value;
		vec.set(i, value);
	}
	return in;
}
// voir opérateur de somme, c'est pareil 
template <class T, class U>
auto operator*(const Vecteur<T> &v1, const Vecteur<U> &v2)  
{	
	assert(v1.dimensions() == v2.dimensions());

	std::common_type_t<T, U> result;

	for (size_t i = 0; i < v1.dimensions(); i++)
		result += v1.get(i) * v2.get(i);
	return result;
}

// Prototypes des fonctions
// inutiles pour ce tp

/*void afficherVecteur(const Vecteur * v, std::ostream & out = std::cout);
Vecteur * lireVecteur(std::istream & in = std::cin);

std::ostream &operator<<(std::ostream &out, const Vecteur &vec);
std::istream &operator>>(std::istream &in, Vecteur &vec);

Vecteur add(const Vecteur *v1, const Vecteur *v2);
T operator*(const Vecteur &v1, const Vecteur &v2);*/
#endif
