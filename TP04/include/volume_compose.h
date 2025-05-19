#ifndef VOLUME_COMPOSE
#define VOLUME_COMPOSE

#include <filtre_compose.h>

class volume_compose : public filtre_compose
{
public:
	volume_compose(double volume);
	void setup() override;

};

#endif
