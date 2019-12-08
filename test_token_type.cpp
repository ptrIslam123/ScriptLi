#include <iostream>
#include "test_token_type.h"
#define TEST_LOG(INF) std::cout << "\n\t\t***|| run test { " << INF << " } ||***\n"


void test_verification_get_tokens(const std::string& text, LexicalGrammar* lexical)
{
	/*TEST_LOG("verification_get_tokens");
	
	std::cout << "\ninput_text = " << text << "\n\n";
	Lexer lexer(text, lexical);
	lexer.run();

	test_show_tokens(lexer.getTokens());*/
}


static void test_show_token_type(const TokenType& type)
{
	switch (type)
	{
	
	case TokenType::NUMBER_INT : {
		std::cout << "type : INT\n";
		break;
	}
	case TokenType::TEXT: {
		std::cout << "type : TEXT\n";
		break;
	}
	case TokenType::NUMBER_DOUBLE: {
		std::cout << "type : DOUBLE\n";
		break;
	}
	case TokenType::CHAR: {
		std::cout << "type : CHAR\n";
		break;
	}

	case TokenType::WORD: {
		std::cout << "type : WORD\n";
		break;
	}


	case TokenType::ADD: {
		std::cout << "type : ADD\n";
		break;
	}
	
	case TokenType::SUB: {
		std::cout << "type : SUB\n";
		break;
	}
	case TokenType::MULT: {
		std::cout << "type : MULT\n";
		break;
	}
	case TokenType::DIV: {
		std::cout << "type : DIV\n";
		break;
	}
	case TokenType::LQ: {
		std::cout << "type : LQ\n";
		break;
	}
	case TokenType::RQ : {
		std::cout << "type : RQ\n";
		break;
	}
	case TokenType::POINT: {
		std::cout << "type : POINT\n";
		break;
	}
	case TokenType::COMMA: {
		std::cout << "type : COMMA\n";
		break;
	}
	
	default:
		std::cout << "\n<undefined type>\n";
	}
}
