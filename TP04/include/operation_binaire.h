#ifndef OPERATION_BINAIRE
#define OPERATION_BINAIRE

#include <filtre_base.h>
#include <cassert>
#include <iostream>
#include <ostream>
template<typename Operator>
class operation_binaire : public filtre_base
{
private:
	Operator op;

public:

	operation_binaire()
	: filtre_base(2,1), op()
	{}

	void calculer()
	{
		//getEntree(0); // entree 0
		//getEntree(1); // entree 1
	
		assert(yaDesEchantillons());
		
		double value;
		value = op(getEntree(0)->extraire(), getEntree(1)->extraire());
	
		getSortie(0)->inserer(value);
		//std::cout << "opbin done; " << std::endl;
	}


};

#endif
