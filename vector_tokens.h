#ifndef _VECTOR_TOKENS_H_
#define _VECTOR_TOKENS_H_

#include <vector>
#include <iostream>
#include "container.h"


class VectorTokens : public Container 
{
private:
	using Vector_t = std::vector<std::unique_ptr<Token>>;

public:
	VectorTokens();
	VectorTokens(const size_t);

	virtual ContainerType getType() const;
	virtual size_t size() const override;
	virtual void push_back(Token*) override;
	virtual void insert(const size_t, Token*) override;
	virtual Token* get(const size_t) override;
	virtual std::unique_ptr<Token>&& getToken(const size_t) override;
	virtual void remove(const size_t) override;
	virtual void clear();

	Vector_t::iterator get_iterator();

private:
	Vector_t tokens;
	Vector_t::iterator it;
};

#endif // !_VECTOR_TOKENS_H_
