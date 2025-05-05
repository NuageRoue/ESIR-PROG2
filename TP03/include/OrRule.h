#ifndef ORRULE
#define ORRULE

#include <AbstractRule.h>
#include <vector>

/// <summary>
/// Represents a logical OR rule that aggregates multiple rules.
/// The OR rule is satisfied if any of its constituent rules are satisfied.
/// Inherits from AbstractRule.
/// </summary>
class OrRule : public AbstractRule
{
protected:
	/// <summary>
	/// A list of rules that are part of this OR rule.
	/// </summary>
	std::vector<AbstractRule*> rules;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="OrRule" /> class.
	/// </summary>
	/// <param name="rules">A vector of rules to be aggregated by this OR rule.</param>
	OrRule(std::vector<AbstractRule*> rules);

	/// <summary>
	/// Destructor for the OrRule class.
	/// Deletes all the rules it aggregates.
	/// </summary>
	~OrRule();

	/// <summary>
	/// Checks if any of the aggregated rules' conditions are met.
	/// </summary>
	/// <returns>True if any rule's condition is met, otherwise false.</returns>
	bool condition() override;

	/// <summary>
	/// Executes the action of the first rule whose condition is met.
	/// </summary>
	void action() override;
};

#endif
