#include "lexer.h"

Lexer::Lexer(const std::string& text, LexicalGrammar* lexical, Container* container)
	:text_(text), lexical_ (lexical), tokens(container)
{}

Lexer::Lexer(std::string&& text, LexicalGrammar* lexical, Container* container)
	: text_(std::move(text)), lexical_(lexical), tokens(container)
{}

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
			continue;
		}

		//tokenizeComment
		if (peek(0) == '/' && peek(1) == '/')
		{
			lexical_->tokenizeComment();
			continue;
		}

		//tokenizeMultiLineComment
		if (peek(0) == '/' && peek(1) == '*')
		{
			lexical_->tokenizeMultiLineComment();
			continue;
		}

		//tokenizeNumber
		if ( isdigit(peek(0)) )
		{
			tokens->push_back(
				lexical_->tokenizeNumber()
			);
			continue;
		}

		//tokenizeWord
		if ( isalpha(peek(0)) )
		{
			tokens->push_back(
				lexical_->tokenizeWord()
			);
			continue;
		}

		//tokenizeOperators
		Token* operators = lexical_->tokenizeOperators();
		if (operators != nullptr)
		{
			tokens->push_back(operators);
			continue;
		}

		//next line
		if ( peek(0) == '\n')
		{
			lexical_->numLine()++;
		}
		next(1);
	}

	tokens->push_back(makeToken(TokenType::EOI,""));
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

std::unique_ptr<Container>&& Lexer::getTokens() 
{
	return std::move(tokens);
}

std::unique_ptr<LexicalGrammar> Lexer::getLexicalGrammar()
{
	return std::move(lexical_);
}

