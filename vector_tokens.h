#ifndef _VECTOR_TOKENS_H_
#define _VECTOR_TOKENS_H_

#include <vector>
#include "container.h"


class VectorTokens : public Container 
{
public:
	VectorTokens();
	VectorTokens(const size_t);
	virtual void push_back(Token*) override;

private:
	std::vector<Token*> tokens;
};

#endif // !_VECTOR_TOKENS_H_
