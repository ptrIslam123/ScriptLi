#include "lexical_grammar.h"
#include "grammar.h"

LexicalGrammar* makeLexicalGrammar(const GrammarType& grammarType, const std::string& text)
{
	switch (grammarType)
	{
		case GrammarType::STD_GRAMMAR: return new  Grammar(text);
		default:return nullptr;
	}
}

LexicalGrammar* makeLexicalGrammar(GrammarType&& grammarType, std::string&& text)
{
	switch (grammarType)
	{
		case GrammarType::STD_GRAMMAR: return new  Grammar(text);
		default: return nullptr;
	}
}