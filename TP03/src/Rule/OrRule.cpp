#include <OrRule.h>
#include <vector>

// Constructor to initialize an OR rule with a given set of rules
OrRule::OrRule(std::vector<AbstractRule*> rules)
    : rules(rules)
{
    // Initialization logic
}

// Method to check if any of the aggregated rules' conditions are met
bool OrRule::condition()
{
    for (AbstractRule* rule : rules)
    {
        if (rule->condition())
            return true;
    }
    return false;
}

// Method to execute the action of the first rule whose condition is met
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

// Destructor to clean up the aggregated rules
OrRule::~OrRule()
{
    for (AbstractRule* rule : rules)
    {
        delete rule;
    }
}

