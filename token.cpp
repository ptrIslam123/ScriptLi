#include "token.h"
#include "base_token.h"
#include "token_type.h"

Token* makeToken(const TokenType& type, const std::string& value)
{
	return new BaseToken(type, value);
}

Token* makeToken(TokenType&& type, std::string&& value)
{
	return new BaseToken(type, value);
}