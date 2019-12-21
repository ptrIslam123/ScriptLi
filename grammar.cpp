//#define _DEBUG_LOG_GRAMMAR
#ifndef _DEBUG_LOG_GRAMMAR
#include <iostream>
#endif // !_DEBUG_LOG_GRAMMAR

#include "base_token.h"
#include "grammar.h"


Grammar::Grammar(const std::string& text)
	:text_(text), position_(0), length_text_(text.size()), countLine(0)
{}

Grammar::Grammar(std::string&& text)
	: text_(text), position_(0), length_text_(text.size()), countLine(0)
{}


Token* Grammar::tokenizeNumber()
{
	bool isFloat = false;
	std::string buffer;
	while (isdigit(get(0)))
	{
		buffer += get(0);
		next(1);

		if (get(0) == '.' && isdigit(get(1)))
		{
			isFloat = true;
			buffer += get(0);
			next(1);
		}
	}
	return new BaseToken(numberType(isFloat), buffer);
}

TokenType Grammar::numberType(const bool number)
{
	if (number)
		return TokenType::NUMBER_DOUBLE;
	return TokenType::NUMBER_INT;
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
{////////
	while ( 0 )
	{
		next(1);
	}
}


Token* Grammar::tokenizeWord()
{
	std::string buffer;
	while ( isalnum(get(0)) || get(0) == '_')
	{
		buffer += get(0);
		next(1);
	}
	return new BaseToken(categoryWord(buffer), buffer);
}

TokenType Grammar::categoryWord(const std::string& word)
{
	for (size_t i = 0; i< sizeof(keyWords_type)/sizeof(keyWords_type[0]); i++)
	{
		if (word[0] == keyWords[i][0])
		{
			if (word == keyWords[i])
			{
				return keyWords_type[i];
			}
		}
	}
	return TokenType::WORD;
}


Token* Grammar::tokenizeCharecter()
{
	next(1);
	std::string buffer;
	buffer += get(0);
	if (get(1) != '\'')
	{
		/// syntacsis error
	}
	next(2);
	return makeToken(TokenType::CHAR, buffer);
}
 
Token* Grammar::tokenizeOperators()
{
	char buffer[3] = { get(0), get(1), '\0' };

	char once_simbol_operator = buffer[0];
	std::string two_simbol_operator(buffer);


	TokenType type = two_charecter_token(std::move(two_simbol_operator));
	if (type != TokenType::UNDEFINE)
	{
		next(2);
		return makeToken(type,"");
	}

	type = one_charecter_token(once_simbol_operator);
	if (type != TokenType::UNDEFINE)
	{
		next(1);
		return makeToken(type, "");
	}
	return nullptr;
}

TokenType Grammar::one_charecter_token(const char letter)
{
	constexpr size_t size = sizeof(one_char_operator) / sizeof(one_char_operator[0]);
	for (size_t i = 0; i < size; i++)
	{
		if (one_char_operator[i] == letter)
		{
			return once_char_operator_t[i];
		}
	}
	return TokenType::UNDEFINE;
}

TokenType Grammar::two_charecter_token(std::string&& oprt)
{
	constexpr size_t size = sizeof(one_char_operator) / sizeof(one_char_operator[0]);
	for (size_t i = 0; i < size; i++)
	{
		if (two_char_operator[i] == oprt)
		{
			return two_char_operator_t[i];
		}
	}
	return TokenType::UNDEFINE;
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

size_t& Grammar::numLine()
{
	return countLine;
}



