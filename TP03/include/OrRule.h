#ifndef ORRULE
#define ORRULE

#include <AbstractRule.h>
#include <vector>

class OrRule : public AbstractRule
{
protected:
	std::vector<AbstractRule*> rules;

public:
	OrRule(std::vector<AbstractRule*> rules);

	bool	condition()	override;
	void	action()	override;


};

#endif
