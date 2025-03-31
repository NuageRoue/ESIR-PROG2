/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/

#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <cstddef>
#include <iostream>
#include <ostream>
#include <cassert>
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
	
	Vecteur(Vecteur &v)
	{
		dimension = v.dimensions();
		values = new T[v.dimensions()];
		for (size_t i = 0; i < v.dimensions(); i++)
			values[i] = v.get(i);
	}
	/* operators */
	


	Vecteur &operator=(const Vecteur &vec)
	{
		if (this != &vec)
		{
			if (values != nullptr) delete[] values; // si on référence déjà quelque chose, on le delete avant
			values = new T[vec.dimensions()];
			dimension = vec.dimensions();
			for (size_t i = 0; i < dimensions(); i++) 
				values[i] = vec.get(i);
		}
		return *this;
	}

	template <class T2>
	Vecteur operator+(const Vecteur<T2> &vec)
	{
		assert(dimensions() == vec.dimensions());

		Vecteur<T> test(vec.dimensions());

		for (size_t i = 0; i < dimensions(); i++)
			test.set(i, get(i) + vec.get(i));
		return test;	
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

template <class T1, class T2>
T1 operator*(const Vecteur<T1> &v1, const Vecteur<T2> &v2)
{	
	assert(v1.dimensions() == v2.dimensions());

	T1 test(0);

	for (size_t i = 0; i < v1.dimensions(); i++)
		test += v1.get(i) * v2.get(i);
	return test;
}

// Prototypes des fonctions

template <class T>
Vecteur<T> * lireVecteur(std::istream & in = std::cin)
{
    size_t _dim;
    std::cout << "Dimension du vecteur : ";
    in >> _dim;
    Vecteur<T> * vec = new Vecteur<T>(_dim);

    for (size_t i = 0; i<_dim; i++)
    {
        T _init;
        std::cout << "Valeur : ";
        in >> _init;
        vec->set(i, _init);
    }
    return vec;
}

/*void afficherVecteur(const Vecteur * v, std::ostream & out = std::cout);
Vecteur * lireVecteur(std::istream & in = std::cin);

std::ostream &operator<<(std::ostream &out, const Vecteur &vec);
std::istream &operator>>(std::istream &in, Vecteur &vec);

Vecteur add(const Vecteur *v1, const Vecteur *v2);
T operator*(const Vecteur &v1, const Vecteur &v2);*/
#endif
