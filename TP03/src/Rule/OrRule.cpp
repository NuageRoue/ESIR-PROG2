#include <OrRule.h>
#include <vector>

OrRule::OrRule(std::vector<AbstractRule*> rules)
: rules(rules)
{}

bool OrRule::condition()
{
	for (AbstractRule* rule : rules)
	{
		if (rule->condition())
			return true;
	}
	return false;
}


void OrRule::action()
{
	for (AbstractRule* rule : rules)
	{
		if (rule->condition())
		{
			rule->action();
			return;
		}
	}
}
