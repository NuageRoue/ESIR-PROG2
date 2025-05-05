#include <MasterOrRule.h>

// Constructor to initialize a MasterOrRule with a master rule and an OR rule
MasterOrRule::MasterOrRule(AbstractRule* masterRule, OrRule* orRule)
    : masterRule(masterRule), orRule(orRule)
{
    // Initialization logic
}

// Method to execute the action based on the conditions of the master rule and the OR rule
void MasterOrRule::action()
{
    if (orRule->condition())
    {
        orRule->action(); // Execute the OR rule's action if its condition is met
    }
    else
    {
        masterRule->action(); // Execute the master rule's action if the OR rule's condition is not met
    }
}

// Method to check if the master rule's condition is met
bool MasterOrRule::condition()
{
    return masterRule->condition(); // The condition of the MasterOrRule is based on the master rule's condition
}

// Destructor to clean up the master rule and the OR rule
MasterOrRule::~MasterOrRule()
{
    delete masterRule;
    delete orRule;
}
