#ifndef _BASE_TOKEN_H_
#define _BASE_TOKEN_H_

#include <string>
#include "token.h"
#include "token_type.h"

class BaseToken : public Token
{
public:
	template<class _TokenType, class _TypeValue>
	BaseToken(_TokenType&& type, _TypeValue&& value);

	virtual TokenType getType() const override;
	virtual std::string getValue() const override;

private:
	TokenType type_;
	std::string value_;
};


template<class _TokenType, class _TypeValue>
inline BaseToken::BaseToken(_TokenType&& type, _TypeValue&& value)
	:type_(std::forward<_TokenType>(type)), value_(std::forward<_TypeValue>(value))
{}


#endif // !_BASE_TOKEN_H_

