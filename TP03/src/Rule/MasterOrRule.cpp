#include <MasterOrRule.h>

MasterOrRule::MasterOrRule(AbstractRule* masterRule, OrRule* orRule)
: masterRule(masterRule), orRule(orRule)
{}

void MasterOrRule::action()
{
	if (orRule->condition())
	{
		orRule->action();
	}
	else 
	{
		masterRule->action();
	}
}

bool MasterOrRule::condition()
{
	return masterRule->condition();
}
