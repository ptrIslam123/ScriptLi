#ifndef _BINARY_EXPR_H_
#define _BINARY_EXPR_H_

#include <iostream>
#include "ast.h"
#include "allocator.h"
#include "container.h"

#define SIZE_ID 6

class BinaryExpression
: public AST
{
public:
	BinaryExpression(std::unique_ptr<Container>&&, const Allocator<NodeAST>&);
	BinaryExpression(std::unique_ptr<Container>&&, Allocator<NodeAST>&&);
	~BinaryExpression();

	virtual NodeAST* build() override;
	void bin_expr_t(NodeAST*);
	void term_t(NodeAST*);
	void fact_t(NodeAST*);

private:
	TokenType getType(const size_t) const;
	Token* getToken(const size_t) const;
	NodeAST* allocNode(TokenType&&);
	NodeAST* allocNode(const TokenType&);
	bool isId(const TokenType&) const;
	bool isBinaryOperator(const TokenType&) const;
	bool isUnaryOperator(const TokenType&) const;
	bool isLQ(const TokenType&, bool*);
	void next(const size_t);


private:
	TokenType idTypes[SIZE_ID] = {
		TokenType::NUMBER_DOUBLE, TokenType::NUMBER_INT,
		TokenType::TEXT, TokenType::CHAR
	};
	std::unique_ptr<Container> container_;
	Allocator<NodeAST> allocator_;
	size_t current_pos_, length_container_;
};




#endif // !_BINARY_EXPR_H_
