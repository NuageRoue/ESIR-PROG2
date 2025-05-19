#ifndef MIXEUR
#define MIXEUR

#include <filtre_compose.h>
#include <vector>
class mixeur : public filtre_compose
{
public:
	mixeur(std::vector<double> volumes);
	
	void setup() override;

};

#endif
