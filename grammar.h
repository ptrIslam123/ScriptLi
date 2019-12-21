#ifndef _GRAMMAR_H_
#define _GRAMMAR_H_

#include <string>
#include "token_type.h"
#include "lexical_grammar.h"

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

	
	std::string keyWords[2] = {"println","scanner"};
	TokenType keyWords_type[2] = {TokenType::PRINTLN, TokenType::SCANNER};


	char one_char_operator[12] = {'+','-','*','/','>','<','=','!','(',')','.',','};
	std::string two_char_operator[12] = {">=","<=","==","!="};

	TokenType once_char_operator_t[12] = {
		TokenType::ADD,TokenType::SUB,TokenType::MULT,TokenType::DIV,TokenType::MORE,TokenType::LESS,
		TokenType::EQULLY,TokenType::BUT,TokenType::LQ,TokenType::RQ,TokenType::POINT,TokenType::COMMA
	};

	TokenType two_char_operator_t[12] = {
		TokenType::MORE_EQ,TokenType::LESS_EQ,TokenType::EQ,TokenType::NO_EQ
	};
};

#endif // !_GRAMMAR_H_

