#ifndef ABSTRACTRULE
#define ABSTRACTRULE

class AbstractRule 
{

public:
	virtual bool condition() = 0;

	virtual void action() = 0;

	virtual ~AbstractRule() = default;
};

#endif
