#ifndef _GRAMMAR_H_
#define _GRAMMAR_H_

#include <string>
#include "token_type.h"
#include "lexical_grammar.h"

#define KEY_WORDS 8
#define ONCE_CHAR_OPERATORS 16
#define TWO_CHAR_OPERATORS 4

class Grammar : public LexicalGrammar
{
public:
	Grammar(const std::string&);
	Grammar(std::string&&);

	virtual Token* tokenizeNumber() override;
	virtual Token* tokenizeString() override;
	virtual Token* tokenizeWord() override;
	virtual Token* tokenizeCharecter() override;

	virtual Token* tokenizeOperators() override;

	virtual void tokenizeComment() override;
	virtual void tokenizeMultiLineComment() override;

	virtual char get(const int) override;
	virtual void next(const int) override;
	virtual size_t& numLine() override;


private:
	TokenType numberType(const bool);
	TokenType categoryWord(const std::string&);

	TokenType one_charecter_token(const char);
	TokenType two_charecter_token(std::string&&);

private:
	std::string text_;
	int position_, length_text_;
	size_t countLine;

	
	std::string keyWords[KEY_WORDS] = {"print","scanner","dec","def","while", "struct","if","else"};
	TokenType keyWords_type[KEY_WORDS] = {
		TokenType::PRINT, TokenType::SCANNER, TokenType::DEC,TokenType::DEF,
		TokenType::WHILE, TokenType::STRUCT, TokenType::IF, TokenType::ELSE
	};


	char one_char_operator[ONCE_CHAR_OPERATORS] = {'+','-','*','/','>','<','=','!','(',')','.',',' , '{','}','[',']'};
	std::string two_char_operator[TWO_CHAR_OPERATORS] = {">=","<=","==","!="};

	TokenType once_char_operator_t[ONCE_CHAR_OPERATORS] = {
		TokenType::ADD,TokenType::SUB,TokenType::MULT,TokenType::DIV,TokenType::MORE,TokenType::LESS,
		TokenType::EQULLY,TokenType::BUT,TokenType::LQ,TokenType::RQ,TokenType::POINT,TokenType::COMMA,
		TokenType::SHAPE_LQ, TokenType::SHAPE_RQ, TokenType::L_SQUARE, TokenType::R_SQUARE
	};

	TokenType two_char_operator_t[TWO_CHAR_OPERATORS] = {
		TokenType::MORE_EQ,TokenType::LESS_EQ,TokenType::EQ,TokenType::NO_EQ
	};
};

#endif // !_GRAMMAR_H_

