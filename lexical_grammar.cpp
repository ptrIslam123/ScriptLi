#include "lexical_grammar.h"
#include "grammar.h"

#define EXCEPTION(INF) std::cout << INF << "\n";	\
						throw;						\

std::unique_ptr<LexicalGrammar>&& makeLexicalGrammar(const GrammarType& grammarType, const std::string& text)
{
	switch (grammarType)
	{
	case GrammarType::STD_GRAMMAR: return std::make_unique<Grammar>(text);
		default:
			EXCEPTION("undefine lexicalGrammar type")
	}
}

std::unique_ptr<LexicalGrammar>&& makeLexicalGrammar(GrammarType&& grammarType, std::string&& text)
{
	switch (grammarType)
	{
	case GrammarType::STD_GRAMMAR: return std::make_unique<Grammar>(text);
		default:
			EXCEPTION("undefine lexicalGrammar type")
	}
}