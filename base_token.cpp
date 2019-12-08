#include "base_token.h"

TokenType BaseToken::getType() const
{
	return type_;
}

std::string BaseToken::getValue() const
{
	return value_;
}
