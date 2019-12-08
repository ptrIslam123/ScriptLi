#include "vector_tokens.h"

VectorTokens::VectorTokens()
	:tokens{ 10 }
{}

VectorTokens::VectorTokens(const size_t size_container)
	:tokens{size_container}
{}

void VectorTokens::push_back(Token* token)
{
	tokens.push_back(token);
}
