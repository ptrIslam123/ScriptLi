//#define _DEBUG_LOG_GRAMMAR
#ifndef _DEBUG_LOG_GRAMMAR
#include <iostream>
#endif // !_DEBUG_LOG_GRAMMAR

#include "base_token.h"
#include "grammar.h"

Grammar::Grammar(const std::string& text)
	:text_(text), position_(0), length_text_(text.size())
{}

Grammar::Grammar(std::string&& text)
	: text_(text), position_(0), length_text_(text.size())
{}


Token* Grammar::tokenizeNumber()
{
	std::string buffer;
	while ( isdigit(get(0)) )
	{
		buffer += get(0);
		next(1);
	}
	return new BaseToken(TokenType::NUMBER_INT, buffer);
}

Token* Grammar::tokenizeOperand()
{
	TokenType tokeneOperands[] = { 
		TokenType::ADD, TokenType::SUB, TokenType::MULT, TokenType::DIV, 
		TokenType::LQ, TokenType::RQ, TokenType::POINT, TokenType::COMMA,
		TokenType::EQULLY
	};

	char operands[] = { '+', '-','*','/','(',')','.',',','=' };
	char currentCharecter = get(0);

	for (int i = 0; i < sizeof(operands); i++)
	{
		if (currentCharecter == operands[i])
		{
			return new BaseToken(tokeneOperands[i], "");
		}
	}
	return nullptr;
}

Token* Grammar::tokenizeString()
{
	next(1);
	std::string buffer;
	while (get(0) != '\"')
	{
		buffer += get(0);
		next(1);
	}
	next(1);
	return new BaseToken(TokenType::TEXT, buffer);
}


void Grammar::tokenizeComment()
{
	while (get(0) != '\n')
	{
		next(1);
	}
	next(1);
}

void Grammar::tokenizeMultiLineComment()
{
}

Token* Grammar::tokenizeWord()
{
	std::string buffer;
	while ( isalpha(get(0)) )
	{
		buffer += get(0);
		next(1);
	}
	return new BaseToken(TokenType::WORD, buffer);
}

char Grammar::get(const int offset)
{
	int pos = position_ + offset;
	if (pos >= length_text_)
	{
		return '\0';
	}
	return text_[pos];
}

void Grammar::next(const int offset_position)
{
	position_ += offset_position;
}


