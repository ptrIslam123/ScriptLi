#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>
#include "token_type.h"

class Token
{
public:
	virtual TokenType getType() const = 0;
	virtual std::string getValue() const = 0;
	virtual size_t getLine() const = 0;
	virtual void setLine(const size_t&) = 0;
};

Token* makeToken(const TokenType&, const std::string&);

Token* makeToken(TokenType&&, std::string&&);


#endif // !_TOKEN_H_

