#ifndef _LIST_TOKENS_H_
#define _LIST_TOKENS_H_

#include <list>
#include "container.h"

class ListTokens : public Container
{
public:
	ListTokens();
	ListTokens(const size_t);
	virtual ContainerType getType() const;
	virtual size_t size() const override;
	virtual void push_back(Token*) override;
	virtual void insert(const size_t, Token*) override;
	virtual Token* get(const size_t) override;
	virtual void remove(const size_t) override;
	virtual void clear();

	std::list<Token*>::iterator get_iterator();

private:
	std::list<Token*> tokens;
	std::list<Token*>::iterator it;
};

#endif // !_LIST_TOKENS_H_