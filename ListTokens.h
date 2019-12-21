#ifndef _LIST_TOKENS_H_
#define _LIST_TOKENS_H_

#include <list>
#include <iostream>
#include "container.h"

class ListTokens : public Container
{
private:
	using List_t = std::list<std::unique_ptr<Token>>;

public:
	ListTokens();
	ListTokens(const size_t);
	virtual ContainerType getType() const;
	virtual size_t size() const override;
	virtual void push_back(Token*) override;
	virtual void insert(const size_t, Token*) override;
	virtual Token* get(const size_t) override;
	virtual std::unique_ptr<Token>&& getToken(const size_t) override;
	virtual void remove(const size_t) override;
	virtual void clear();

	List_t::iterator get_iterator();

private:
	List_t tokens;
	List_t::iterator it;
};

#endif // !_LIST_TOKENS_H_