#ifndef SILLY
#define SILLY

#include "Environment.h"
#include "Vector2.h"
#include <AntBase.h>

class SillyAnt : public AntBase
{
private:

public:
	SillyAnt(Environment *env, Vector2<float> initialPos, Anthill *anthill);

	void update() override;
};

#endif
