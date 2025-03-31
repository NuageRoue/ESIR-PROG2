/** \brief Ce fichier doit contenir l'ensemble des implémentations
relatives à la classe vecteur et aux fonctionnalités la concernant */
/// les briefs sont dans le header, le reste est relativement explicite
#include <cassert>
#include <iostream>
#include "vecteur.h"




	


Vecteur::Vecteur(size_t dim, float baseValue) : dimension(dim), values(new float[dim])
{
	assert(dimension > 0);
	for (size_t i = 0; i < dimension; i++)
		values[i] = baseValue;
	std::cout << "construction d'un vecteur à " << dim << " dimensions, de valeur initiale " << baseValue << std::endl;
}

Vecteur::~Vecteur()
{
	delete[] values;// on delete le tableau
}

Vecteur::Vecteur(Vecteur &v)
{
	dimension = v.dimensions();
	values = new float[v.dimensions()];
	for (size_t i = 0; i < v.dimensions(); i++) // copie en profondeur
		values[i] = v.get(i);
}



Vecteur &Vecteur::operator=(const Vecteur &vec)
{
	if (this != &vec)
	{
		if (values != nullptr) delete[] values; // si on référence déjà quelque chose, on le delete avant
		values = new float[vec.dimensions()];
		dimension = vec.dimensions();
		for (size_t i = 0; i < dimensions(); i++) // copie en profondeur
			values[i] = vec.get(i);
	}
	return *this;

}

float& Vecteur::operator[](size_t i)
{
	return (float &)get(i);
}

const float& Vecteur::operator[](size_t i) const
{
	return get(i);	
}



Vecteur Vecteur::operator+(const Vecteur &vec) // on ne renvoie pas un pointeur parce que sinon on risque une fuite de mémoire si on perd la référence à la somme (dans le cas d'une triple somme)
{
	assert(dimensions() == vec.dimensions());

	Vecteur test(vec.dimensions());

	for (size_t i = 0; i < dimensions(); i++)
		test.set(i, get(i) + vec.get(i));
	return test;	
}


const float &Vecteur::get(size_t dim) const
{
	assert(dim < dimension);
	return (const float&)values[dim];
}

void Vecteur::set(size_t dim, float value)
{
	assert(dim < dimension);
	values[dim] = value;
}

const size_t& Vecteur::dimensions() const
{
	return dimension;
}


void afficherVecteur(const Vecteur * v, std::ostream & out)
{
	out << "Vecteur: ";
	for (size_t i = 0; i < v->dimensions(); i++)
		out << v->get(i) << "; ";
	out << std::endl;
}


Vecteur * lireVecteur(std::istream & in)
{
	size_t dimension;
	//std::cout << "donnez la dimension du vecteur: ";
	in >> dimension;
	//std::cout << "vecteur de dimension " << dimension;

	Vecteur *vector = new Vecteur(dimension);
	for (size_t i = 0; i < dimension; i++)
	{
		float value;
      		//std::cout << "donnez la coordonnee d'indice " << i << ": ";
      		in >> value;
		vector->set(i, value);
	}

	return vector;
}


std::ostream &operator<<(std::ostream &out, const Vecteur &vec)
{
	out << "vecteur: ";
	for (size_t i = 0; i < vec.dimensions(); i++)
		out << vec.get(i) << ";";
	return out;
}


std::istream &operator>>(std::istream &in, Vecteur &vec)
{
	float value;
	for (size_t i = 0; i < vec.dimensions(); i++)
	{
		in >> value;
		vec.set(i, value);
	}
	return in;
}

Vecteur add(const Vecteur *v1, const Vecteur *v2)
{
	assert(v1->dimensions() == v2->dimensions());

	Vecteur toReturn(v1->dimensions());

	for (size_t i = 0; i < v1->dimensions(); i++)
		toReturn.set(i, v1->get(i) + v2->get(i));
	return toReturn;
}
float operator*(const Vecteur &v1, const Vecteur &v2)
{	
	assert(v1.dimensions() == v2.dimensions());

	float test(0);

	for (size_t i = 0; i < v1.dimensions(); i++)
		test += v1.get(i) * v2.get(i);
	return test;	
}
