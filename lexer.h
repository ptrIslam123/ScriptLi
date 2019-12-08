#ifndef _LEXER_H_
#define _LEXER_H_
//#define _DEBUG_LEXER_

#include <string>
#include "lexical_grammar.h"
#include "token.h"
#include "container.h"

class Lexer
{
public:
	Lexer(const std::string&, LexicalGrammar*, Container*);
	Lexer(std::string&&, LexicalGrammar*, Container*);
	~Lexer();

	void run();

	std::string getText() const;
	Container* getTokens() const;

private:
	char peek(const int);
	void next(const int);

private:
	Container* tokens;
	LexicalGrammar* lexical_;
	std::string text_;
};

#endif // !_LEXER_H_
