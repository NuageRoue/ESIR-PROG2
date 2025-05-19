#ifndef MULTIPLICATEUR
#define MULTIPLICATEUR

#include <filtre_base.h>

class multiplicateur : public filtre_base
{
public:

	multiplicateur();
	
	void calculer() override;
};

#endif
