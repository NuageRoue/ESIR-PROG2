#include "Liste.h"


/**
   3.2.1 chercher une valeur dans une liste triée, nom de la fonction fonction : chercherTri
   @param premier : itérateur positionné sur le premier élément
   @param dernier : itérateur positionné après le dernier élément
   @param x : valeur à chercher
   @return position du premier élément de valeur >= x
   ou end() si un tel élément n'existe pas
 */
template <class InputIterator, class T>
InputIterator chercherTri(InputIterator premier, InputIterator dernier, const T &x)
{
	while (premier != dernier)
	{
		if (*premier >= x)
		{
			return premier;
		}

		++premier;
	}
	return dernier;
}


/**
   3.2.2 créer une copie triée par valeurs croissantes d'une liste, nom de la fonction fonction : copierTri
   @param l : liste à copier
   @return liste triée
*/
template <class T>
Liste<T> *copierTri(Liste<T> &toCopy)
{
	Liste<T> *toReturn = new Liste<T>();
	using iterator = typename Liste<T>::iterator;
	for (iterator i = toCopy.begin(); i != toCopy.end(); ++i)
	{
		toReturn->insert(chercherTri(toReturn->begin(), toReturn->end(), *i), *i);
	}

	return toReturn;

}
