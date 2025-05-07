#include <signal_constant.h>
#include <cassert>
#include <imp_flot.h>

signal_constant::signal_constant(double value)
: value(value), f_ptr(std::make_shared<imp_flot>())
{
	
}


unsigned int signal_constant::nbSorties() const
{
	return 1;
}

const std::shared_ptr<flot> & signal_constant::getSortie(unsigned int numsortie) const
{
	assert(numsortie ==0);
	return f_ptr;
	
}

void signal_constant::calculer()
{
	f_ptr->inserer(value);
}
