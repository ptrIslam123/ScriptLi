#ifndef _EXPR_AST_H_
#define _EXPR_AST_H_

#include <iostream>
#include "ast.h"
#include "base_ast_functionality.h"
#include "allocator.h"
#include "container.h"

#define SIZE_ID 6
#define SIZE_LOG_OPERATOR 4
#define SIZE_COND_OPERATOR 6

class Expression : public AST, BaseASTFunctionality
{
public:
	Expression(Container*, const Allocator<NodeAST>&, size_t&);
	Expression(Container*, Allocator<NodeAST>&&, size_t&);
	~Expression();

	virtual NodeAST* build() override;

	void log_expr_t(NodeAST*, bool lq_operator = false);
	void cond_expr_t(NodeAST*);
	void bin_expr_t(NodeAST*);
	void term_t(NodeAST*);
	void fact_t(NodeAST*);

	bool isId(const TokenType&) const;
	bool isLogOperator(const TokenType&) const;
	bool isCondOperator(const TokenType&) const;
	bool isBinaryOperator(const TokenType&) const;
	bool isUnaryOperator(const TokenType&) const;
	bool isLQ(const TokenType&) const;
	bool isRQ(const TokenType&) const;

private:
	TokenType idTypes[SIZE_ID] = {
		TokenType::WORD,
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
	Allocator<NodeAST> allocator_;
};

#endif // !_EXPR_AST_H_
