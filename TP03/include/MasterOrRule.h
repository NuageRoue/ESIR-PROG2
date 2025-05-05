#ifndef MASTERORRULE
#define MASTERORRULE

#include "AbstractRule.h"
#include <OrRule.h>

/// <summary>
/// Represents a rule that combines a master rule with an OR rule.
/// The master rule's condition must be true for any action to occur.
/// If the OR rule's condition is met, its action is executed; otherwise, the master rule's action is executed.
/// Inherits from AbstractRule.
/// </summary>
class MasterOrRule : public AbstractRule
{
protected:
	/// <summary>
	/// The master rule whose condition must be satisfied.
	/// </summary>
	AbstractRule* masterRule;

	/// <summary>
	/// The OR rule that aggregates multiple rules.
	/// </summary>
	OrRule* orRule;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="MasterOrRule" /> class.
	/// </summary>
	/// <param name="masterRule">The master rule.</param>
	/// <param name="orRule">The OR rule.</param>
	MasterOrRule(AbstractRule* masterRule, OrRule* orRule);

	/// <summary>
	/// Checks if the master rule's condition is met.
	/// </summary>
	/// <returns>True if the master rule's condition is met, otherwise false.</returns>
	bool condition() override;

	/// <summary>
	/// Executes the action of the OR rule if its condition is met; otherwise, executes the master rule's action.
	/// </summary>
	void action() override;

	/// <summary>
	/// Destructor for the MasterOrRule class.
	/// Deletes the master rule and the OR rule.
	/// </summary>
	~MasterOrRule();
};

#endif
