#include "vector_tokens.h"
#include "base_token.h"

using Vector_t = std::vector<std::unique_ptr<Token>>;

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
	std::unique_ptr<Token> value(token);
	tokens.push_back(std::move( value ));
}

void VectorTokens::insert(const size_t index, Token* token)
{
	it = tokens.begin();
	it += index;
	std::unique_ptr<Token> value(token);
	tokens.insert(it, std::move(value) );
}

Token* VectorTokens::get(const size_t index)
{
	return tokens[index].get();
}

std::unique_ptr<Token>&& VectorTokens::getToken(const size_t index)
{
	return std::move( tokens[index] );
}

void VectorTokens::remove(const size_t index)
{
	it = tokens.begin();
	it += index;
	tokens.erase(it);
}

void VectorTokens::clear()
{
	tokens.clear();
}

Vector_t::iterator VectorTokens::get_iterator()
{
	return it;
}
