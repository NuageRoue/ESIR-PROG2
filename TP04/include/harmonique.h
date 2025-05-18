#ifndef HARMONIQUE
#define HARMONIQUE

#include <producteur_base.h>

class harmonique : public producteur_base
{

protected:
	double freqw, shiftw;
	int i;
public:

	harmonique(double f, double shift = 0);
	void calculer() override;

};

#endif
