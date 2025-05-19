#ifndef CONSOMMATEUR_BASE
#define CONSOMMATEUR_BASE

#include "consommateur.h"
#include <memory>
#include <flot.h>
#include <vector>

class consommateur_base : public virtual consommateur
{
protected:
	std::vector<std::shared_ptr<flot>> flots_entrees;
	int nbSortie;

public:

	consommateur_base(int nbEntrees);
	virtual ~consommateur_base() = default;

	virtual unsigned int nbEntrees() const override;
	virtual const std::shared_ptr<flot> & getEntree(unsigned int numentree) const override;
	virtual bool yaDesEchantillons() const override;
	virtual void connecterEntree(const std::shared_ptr<flot> & f, unsigned int numentree) override;


};

#endif
