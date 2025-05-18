#ifndef PRODUCTEUR_BASE
#define PRODUCTEUR_BASE

#include "consommateur.h"
#include <memory>
#include <flot.h>
#include <vector>

class consommateur_base : public consommateur
{
protected:
	virtual void connecterEntree(const std::shared_ptr<flot> & f, unsigned int numentree) override;
	std::vector<std::shared_ptr<flot>> flots;
	int nbSortie;

public:

	consommateur_base(int nbEntrees);
	~consommateur_base();

	virtual unsigned int nbEntrees() const override;
	virtual const std::shared_ptr<flot> & getEntree(unsigned int numentree) const override;
	virtual bool yaDesEchantillons() const override;


};

#endif
