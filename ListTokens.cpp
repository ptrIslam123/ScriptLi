#include "ListTokens.h"

using List_t = std::list<std::unique_ptr<Token>>;

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
	std::unique_ptr<Token> value(token);
	tokens.push_back(std::move(value));
}

void ListTokens::insert(const size_t, Token* token)
{
	it = tokens.begin();
	std::unique_ptr<Token> value(token);
	tokens.insert(it, std::move (value));
}

Token* ListTokens::get(const size_t index)
{
	it = tokens.begin();
	std::advance(it, index);

	return (*it).get();
}

std::unique_ptr<Token>&& ListTokens::getToken(const size_t index)
{
	it = tokens.begin();
	std::advance(it, index);
	return std::move(*it);
}

void ListTokens::remove(const size_t index)
{
	it = tokens.begin();
	std::advance(it, index);
	tokens.erase(it);
}

void ListTokens::clear()
{
	tokens.clear();
}

List_t::iterator ListTokens::get_iterator()
{
	return it;
}
