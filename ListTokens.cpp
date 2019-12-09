#include "ListTokens.h"

ListTokens::ListTokens()
	:tokens{10}
{}

ListTokens::ListTokens(const size_t size_container)
	:tokens{size_container}
{}

ContainerType ListTokens::getType() const
{
	return ContainerType::List;
}

size_t ListTokens::size() const
{
	return tokens.size();
}

void ListTokens::push_back(Token* token)
{
	tokens.push_back(token);
}

void ListTokens::insert(const size_t, Token* token)
{
	it = tokens.begin();
	tokens.insert(it, token);
}

Token* ListTokens::get(const size_t index)
{
	it = tokens.begin();
	std::advance(it, index);
	return *it;
}

void ListTokens::remove(const size_t index)
{
	it = tokens.begin();
	std::advance(it, index);
	tokens.erase(it);
}

void ListTokens::clear()
{
}

std::list<Token*>::iterator ListTokens::get_iterator()
{
	return it;
}
