#ifndef MASTERORRULE
#define MASTERORRULE

#include "AbstractRule.h"
#include <OrRule.h>

class MasterOrRule : public AbstractRule
{

protected:
	AbstractRule* masterRule;
	OrRule* orRule;

public:
	MasterOrRule(AbstractRule* masterRule, OrRule* orRule);

	bool	condition()	override;
	void	action()	override;

};

#endif
