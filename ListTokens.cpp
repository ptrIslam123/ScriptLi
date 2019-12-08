#include "ListTokens.h"

ListTokens::ListTokens()
	:tokens{10}
{}

ListTokens::ListTokens(const size_t size_container)
	:tokens{size_container}
{}

void ListTokens::push_back(Token* token)
{
	tokens.push_back(token);
}
