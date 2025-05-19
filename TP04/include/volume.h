#ifndef VOLUME
#define VOLUME

#include <filtre_base.h>
#include <multiplicateur.h>
#include <signal_constant.h>
class volume : public filtre_base
{
private:
	signal_constant vol;
	multiplicateur mult;
public:
	volume(double volume);

	void calculer() override;

	void setup();

};
#endif

