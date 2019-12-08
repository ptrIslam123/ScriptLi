#ifndef _LIST_TOKENS_H_
#define _LIST_TOKENS_H_

#include <list>
#include "container.h"

class ListTokens : public Container
{
public:
	ListTokens();
	ListTokens(const size_t);

	virtual void push_back(Token*) override;

private:
	std::list<Token*> tokens;
};

#endif // !_LIST_TOKENS_H_