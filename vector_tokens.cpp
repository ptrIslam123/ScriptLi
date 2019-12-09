#include "vector_tokens.h"

VectorTokens::VectorTokens()
	:tokens{ 10 }, it(tokens.begin())
{}

VectorTokens::VectorTokens(const size_t size_container)
	:tokens{size_container}, it(tokens.begin())
{}

ContainerType VectorTokens::getType() const
{
	return ContainerType::Vector;
}

size_t VectorTokens::size() const
{
	return tokens.size();
}

void VectorTokens::push_back(Token* token)
{
	tokens.push_back(token);
}

void VectorTokens::insert(const size_t index, Token* token)
{
	it = tokens.begin();
	it += index;
	tokens.insert(it, token);
}

Token* VectorTokens::get(const size_t index)
{
	return tokens[index];
}

void VectorTokens::remove(const size_t index)
{
	it = tokens.begin();
	it += index;
	tokens.erase(it);
}

void VectorTokens::clear()
{
}

std::vector<Token*>::iterator VectorTokens::get_iterator()
{
	return it;
}
