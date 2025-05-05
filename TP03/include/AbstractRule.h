#ifndef ABSTRACTRULE
#define ABSTRACTRULE

/// <summary>
/// An abstract base class representing a rule with a condition and an action.
/// </summary>
class AbstractRule
{
public:
	/// <summary>
	/// Checks if the condition of the rule is met.
	/// </summary>
	/// <returns>True if the condition is met, otherwise false.</returns>
	virtual bool condition() = 0;

	/// <summary>
	/// Executes the action associated with the rule.
	/// </summary>
	virtual void action() = 0;

	/// <summary>
	/// Virtual destructor for the rule.
	/// </summary>
	virtual ~AbstractRule() = default;
};



#endif
