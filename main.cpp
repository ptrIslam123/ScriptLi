#include <iostream>
#include <vector>

#include "token.h"
#include "lexical_grammar.h"
#include "container.h"
#include "lexer.h"

#include "vector_tokens.h"

int main()
{


	std::string data = "10,20";
	auto lexical = makeLexicalGrammar(GrammarType::STD_GRAMMAR, data);
	Container* tokens = makeContainer(ContainerType::List, 0);


	Lexer lexer(data, lexical, tokens);

	lexer.run();

	Container* container = lexer.getTokens();

	std::cout << "size = " << container->size() << "\n";

	for (size_t i = 0; i < container->size(); i++)
	{
		std::cout << "value : " << (container->get(i))->getValue() << "\n";
	}

	return 0;
}