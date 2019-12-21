#ifndef _LEXER_H_
#define _LEXER_H_
//#define _DEBUG_LEXER_

#include <iostream>
#include <string>
#include "lexical_grammar.h"
#include "token.h"
#include "container.h"

class Lexer
{
public:
	Lexer(const std::string&, LexicalGrammar*, Container*);
	Lexer(
		const std::string&, 
		std::unique_ptr<LexicalGrammar>,
		std::unique_ptr<Container>
	);
	Lexer(std::string&&, LexicalGrammar*, Container*);
	~Lexer();

	void run();

	std::string getText() const;
	std::unique_ptr<Container>&& getTokens();
	std::unique_ptr<LexicalGrammar> getLexicalGrammar();

private:
	char peek(const int);
	void next(const int);

private:
	std::unique_ptr<Container> tokens;
	std::unique_ptr<LexicalGrammar> lexical_;
	std::string text_;
};


#endif // !_LEXER_H_
