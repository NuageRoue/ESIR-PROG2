#ifndef IMP_FLOT
#define IMP_FLOT

#include "flot.h"
#include <deque>


class imp_flot : public flot
{
private:
	std::deque<double> samples;

public:
	imp_flot();
	

	void inserer(double echantillon) override;
	

	double extraire() override;
	

	bool vide() const override;
};

#endif
