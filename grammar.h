#ifndef _GRAMMAR_H_
#define _GRAMMAR_H_

#include <string>
#include "lexical_grammar.h"

class Grammar : public LexicalGrammar
{
public:
	Grammar(const std::string&);
	Grammar(std::string&&);

	virtual Token* tokenizeNumber() override;
	virtual Token* tokenizeOperand() override;
	virtual Token* tokenizeString() override;

	virtual void tokenizeComment() override;
	virtual void tokenizeMultiLineComment() override;

	virtual Token* tokenizeWord() override;

	virtual char get(const int) override;
	virtual void next(const int) override;

private:
	std::string text_;
	int position_, length_text_;
};

#endif // !_GRAMMAR_H_

