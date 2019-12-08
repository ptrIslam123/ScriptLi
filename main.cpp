#include <iostream>
#include "token.h"
#include "lexical_grammar.h"
#include "container.h"
#include "lexer.h"

int main()
{

	std::string data = "int main()\n{\n}\n";
	auto lexical = makeLexicalGrammar(GrammarType::STD_GRAMMAR, data);
	auto tokens = makeContainer(ContainerType::List, 10);

	Lexer lexer(data, lexical, tokens);

	lexer.run();

	return 0;
}