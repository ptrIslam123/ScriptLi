#ifndef _LEXICAL_GRAMMAR_H_
#define _LEXICAL_GRAMMAR_H_

#include "token.h"

enum class GrammarType
{
	STD_GRAMMAR
};

class LexicalGrammar
{
public:
	virtual Token* tokenizeNumber() = 0;
	virtual Token* tokenizeString() = 0;
	virtual Token* tokenizeCharecter() = 0;
	virtual Token* tokenizeWord() = 0;

	virtual Token* tokenizeOperators() = 0;

	virtual void tokenizeComment() = 0;
	virtual void tokenizeMultiLineComment() = 0;

	virtual char get(const int) = 0;
	virtual void next(const int) = 0;

	virtual size_t& numLine() = 0;
};


LexicalGrammar* makeLexicalGrammar(const GrammarType&, const std::string&);
LexicalGrammar* makeLexicalGrammar(GrammarType&&, std::string&&);


#endif // !_LEXICAL_GRAMMAR_H_
