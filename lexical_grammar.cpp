#include "lexical_grammar.h"
#include "grammar.h"

#define EXCEPTION(INF) std::cout << INF << "\n";	\
						throw;						\

LexicalGrammar* makeLexicalGrammar(const GrammarType& grammarType, const std::string& text)
{
	switch (grammarType)
	{
	case GrammarType::STD_GRAMMAR: return new Grammar(text);
		default:
			EXCEPTION("undefine lexicalGrammar type")
	}
}

LexicalGrammar* makeLexicalGrammar(GrammarType&& grammarType, std::string&& text)
{
	switch (grammarType)
	{
	case GrammarType::STD_GRAMMAR: return new Grammar(std::move(text));
		default:
			EXCEPTION("undefine lexicalGrammar type")
	}
}