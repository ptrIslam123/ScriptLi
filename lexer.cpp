#include <iostream>
#include "lexer.h"

Lexer::Lexer(const std::string& text, LexicalGrammar* lexical, Container* container)
	:text_(text), lexical_(lexical), tokens(container)
{}

Lexer::Lexer(std::string&& text, LexicalGrammar* lexical, Container* container)
	: text_(text), lexical_(lexical), tokens(container)
{}

Lexer::~Lexer()
{
	delete tokens;
	delete lexical_;

	tokens = nullptr;
	lexical_ = nullptr;
}


void Lexer::run()
{
	Token* token;
	while (peek(0) != '\0')
	{
		//tokenizeString
		if (peek(0) == '\"')
		{
			tokens->push_back(
				lexical_->tokenizeString()
			);
			next(1);
			continue;
		}

		//tokenizeComment
		if (peek(0) == '/' && peek(1) == '/')
		{
			lexical_->tokenizeComment();
			next(1);
			continue;
		}

		//tokenizeMultiLineComment
		if (peek(0) == '/' && peek(1) == '*')
		{
			lexical_->tokenizeMultiLineComment();
			next(1);
			continue;
		}

		//tokenizeNumber
		if ( isdigit(peek(0)) )
		{
			tokens->push_back(
				lexical_->tokenizeNumber()
			);
			next(1);
			continue;
		}

		//tokenizeWord
		if ( isalpha(peek(0)) )
		{
			tokens->push_back(
				lexical_->tokenizeWord()
			);
			next(1);
			continue;
		}

		//tokenizeOperand
		token = lexical_->tokenizeOperand();
		if ( token != nullptr)
		{
			tokens->push_back(token);
			next(1);
			continue;
		}

		next(1);
	}
}

char Lexer::peek(const int position)
{
	return lexical_->get(position);
}

void Lexer::next(const int offset)
{
	lexical_->next(offset);
}

std::string Lexer::getText() const
{
	return text_;
}

Container* Lexer::getTokens() const
{
	return tokens;
}


