#include <imp_flot.h>
#include <cassert>

imp_flot::imp_flot()
{}
	

void imp_flot::inserer(double echantillon) 
{
	samples.push_back(echantillon);
}
	

double imp_flot::extraire() 
{
	assert(!vide());

	double sample = samples.front();
	samples.pop_front();
	return sample;
}	

bool imp_flot::vide() const 
{
	return samples.empty();
}
