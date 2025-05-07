#ifndef SIGNAL_CONSTANT
#define SIGNAL_CONSTANT

#include <memory>
#include <producteur.h>

class signal_constant : public producteur
{
private:
	double value;
	std::shared_ptr<flot> f_ptr;
public:
	signal_constant(double value);

	virtual ~signal_constant() = default;
	unsigned int nbSorties() const override;
	const std::shared_ptr<flot> & getSortie(unsigned int numsortie) const override;

	void calculer() override;
};

#endif
