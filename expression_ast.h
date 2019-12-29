#ifndef _EXPR_AST_H_
#define _EXPR_AST_H_

#include <iostream>
#include "ast.h"
#include "allocator.h"
#include "container.h"

#define SIZE_ID 5
#define SIZE_LOG_OPERATOR 4
#define SIZE_COND_OPERATOR 6

class Expression : public AST
{
public:
	Expression(std::unique_ptr<Container>&&, const Allocator<NodeAST>&);
	Expression(std::unique_ptr<Container>&&, Allocator<NodeAST>&&);
	~Expression();

	virtual NodeAST* build() override;

	void log_expr_t(NodeAST*, bool lq_operator = false);
	void cond_expr_t(NodeAST*);
	void bin_expr_t(NodeAST*);
	void term_t(NodeAST*);
	void fact_t(NodeAST*);

private:
	TokenType getType(const size_t) const;

	Token* getToken(const size_t) const;
	NodeAST* allocNode(TokenType&&);
	NodeAST* allocNode(const TokenType&);

	bool isId(const TokenType&) const;
	bool isLogOperator(const TokenType&) const;
	bool isCondOperator(const TokenType&) const;
	bool isBinaryOperator(const TokenType&) const;
	bool isUnaryOperator(const TokenType&) const;
	bool isLQ(const TokenType&) const;
	bool isRQ(const TokenType&) const;

	void next(const size_t);


private:
	TokenType idTypes[SIZE_ID] = {
		TokenType::NUMBER_DOUBLE, TokenType::NUMBER_INT,
		TokenType::TEXT, TokenType::CHAR, TokenType::BOOL
	};

	TokenType logOperators[SIZE_LOG_OPERATOR] = {
		TokenType::BUT, TokenType::NO_EQ,
		TokenType::AND, TokenType::OR
	};

	TokenType condOperators[SIZE_COND_OPERATOR] = {
		TokenType::EQULLY, TokenType::MORE,
		TokenType::LESS, TokenType::MORE_EQ,
		TokenType::LESS_EQ, TokenType::EQ
	};

	std::unique_ptr<Container> container_;
	Allocator<NodeAST> allocator_;
	size_t current_pos_, length_container_;
};

#endif // !_EXPR_AST_H_
