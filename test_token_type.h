#ifndef _TEST_TOKEN_TYPE_H_
#define _TEST_TOKEN_TYPE_H_

#include "token_type.h"
#include "lexical_grammar.h"
#include "lexer.h"


void test_verification_get_tokens(const std::string&, LexicalGrammar*);



static void test_show_token_type(const TokenType&);

template<class _Array>
static void test_show_tokens(_Array&& tokens);

template<class _Array>
static void test_show_tokens(_Array&& tokens)
{
	for (auto iterator = tokens.cbegin(); iterator != tokens.cend(); iterator++)
	{
		test_show_token_type((*iterator)->getType());
		std::cout << "value : " << (*iterator)->getValue() << "\n\n";
	}
}


#endif // !_TEST_TOKEN_TYPE_H_

