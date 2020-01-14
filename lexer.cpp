#include "lexer.h"

Lexer::Lexer(
	const std::string& text,
	std::unique_ptr<LexicalGrammar>&& lexical, 
	std::unique_ptr<Container>&& container
)
	:text_(text), 
	lexical_(std::move(lexical)), 
	tokens(std::move(container))
{}

Lexer::Lexer(
	std::string&& text,
	std::unique_ptr<LexicalGrammar>&& lexical,
	std::unique_ptr<Container>&& container
)
	: text_(std::move(text)),
	lexical_(std::move(lexical)),
	tokens(std::move(container))
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

std::unique_ptr<Container>&& 
getResult_of_the_Lexer(
	const std::string& data, 
	GrammarType&& lexical_type,
	ContainerType&& container_type
)
{
	Lexer lexer(
		data, 
		makeLexicalGrammar(std::move(lexical_type),data),
		makeContainer(std::move(container_type),0)
	);

	lexer.run();
	return std::move( lexer.getTokens() );
}

std::unique_ptr<Container>&&
getResult_of_the_Lexer(
	std::string&& data,
	GrammarType&& lexical_type,
	ContainerType&& container_type
)
{
	Lexer lexer(
		std::move(data),
		makeLexicalGrammar(std::move(lexical_type), std::move(data)),
		makeContainer(std::move(container_type), 0)
	);

	lexer.run();
	return std::move(lexer.getTokens());
}
