#include "base_token.h"

TokenType BaseToken::getType() const
{
	return type_;
}

std::string BaseToken::getValue() const
{
	return value_;
}

size_t BaseToken::getLine() const
{
	return num_line_;
}

void BaseToken::setLine(const size_t& num_line)
{
	num_line_ = num_line;
}
