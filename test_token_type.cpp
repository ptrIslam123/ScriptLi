#include <iostream>
#include "test_token_type.h"
#define TEST_LOG(INF) std::cout << "\n\t\t***|| run test { " << INF << " } ||***\n"
#define PRINT_T(INF) std::cout << INF << "\n";\
					break

void test_show_tokens(Container* tokens)
{
	TEST_LOG("show_tokens");

	size_t size = tokens->size();
	Token* token = nullptr;

	for (size_t i = 0; i < size; i++)
	{
		token = tokens->get(i);
		std::cout << "type : ";
		test_printTokenType( token->getType() );
		std::cout << "value : " <<  token->getValue() << "\n";
		std::cout << "\n";
	}
}

void test_printTokenType(const TokenType& type)
{
	switch (type)
	{
	case TokenType::NUMBER_INT: PRINT_T("INT");
	case TokenType::NUMBER_DOUBLE: PRINT_T("DOUBLE");
	case TokenType::TEXT: PRINT_T("TEXT");
	case TokenType::CHAR: PRINT_T("CHAR");

	case TokenType::ADD: PRINT_T("ADD");
	case TokenType::SUB: PRINT_T("SUB");
	case TokenType::MULT: PRINT_T("MULT");
	case TokenType::DIV: PRINT_T("DIV");
	case TokenType::POINT: PRINT_T("POINT");
	case TokenType::COMMA: PRINT_T("COMMA");
	case TokenType::EQULLY: PRINT_T("EQULLY");
	case TokenType::LQ: PRINT_T("LQ");
	case TokenType::RQ: PRINT_T("RQ");

	case TokenType::LESS: PRINT_T("LESS");
	case TokenType::LESS_EQ: PRINT_T("LESS_EQ");
	case TokenType::MORE: PRINT_T("MORE");
	case TokenType::MORE_EQ: PRINT_T("MORE_EQ");
	case TokenType::EQ: PRINT_T("EQ");
	case TokenType::NO_EQ: PRINT_T("NO_EQ");
	case TokenType::BUT: PRINT_T("BUT");
	
	case TokenType::SHAPE_LQ: PRINT_T("SHAPRE_LQ");
	case TokenType::SHAPE_RQ: PRINT_T("SHAPE_RQ");
	case TokenType::L_SQUARE: PRINT_T("L_SQUARE");
	case TokenType::R_SQUARE: PRINT_T("R_SQUARE");

	case TokenType::WORD: PRINT_T("WORD");

	case TokenType::PRINT: PRINT_T("PRINT");
	case TokenType::SCANNER: PRINT_T("SCANNER");
	case TokenType::STRUCT: PRINT_T("STRUCT");
	case TokenType::DEC: PRINT_T("DEC");
	case TokenType::DEF: PRINT_T("DEF");
	case TokenType::WHILE: PRINT_T("WHILE");
	case TokenType::IF: PRINT_T("IF");
	case TokenType::ELSE: PRINT_T("ELSE");
	case TokenType::RET: PRINT_T("RET");

	case TokenType::EOI: PRINT_T("EOI");

	default: PRINT_T("error : undefained type");
	}
}
