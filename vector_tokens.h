#ifndef _VECTOR_TOKENS_H_
#define _VECTOR_TOKENS_H_

#include <vector>
#include "container.h"


class VectorTokens : public Container 
{
public:
	VectorTokens();
	VectorTokens(const size_t);

	virtual ContainerType getType() const;
	virtual size_t size() const override;
	virtual void push_back(Token*) override;
	virtual void insert(const size_t, Token*) override;
	virtual Token* get(const size_t) override;
	virtual void remove(const size_t) override;
	virtual void clear();

	std::vector<Token*>::iterator get_iterator();

private:
	std::vector<Token*> tokens;
	std::vector<Token*>::iterator it;
};

#endif // !_VECTOR_TOKENS_H_
