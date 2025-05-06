#ifndef IMP_FLOT
#define IMP_FLOT

#include "flot.h"


class imp_flot : flot
{
	
	void inserer(double echantillon) override;
	double extraire() override;
	bool vide() const override;
};

#endif
