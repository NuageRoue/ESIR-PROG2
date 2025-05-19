#include "producteur_base.h"
#include <cmath>
#include <harmonique.h>
#include <constantes.h>

harmonique::harmonique(double freq, double shift)
: producteur_base(1), freqw(freq), shiftw(shift), i(0)
{
}

void harmonique::calculer()
{
	double value;
	value =  std::sin(((double)i/MixageSonore::frequency)*2*MixageSonore::pi * freqw + shiftw);
	i++;
	flots_sortie[0]->inserer(value);
}
