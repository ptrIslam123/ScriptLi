#include "binary_expr.h"

#define SYNTAX_ERROR(DEBUG_INF) std::cout << "exeption\n"; \
								throw DEBUG_INF \

BinaryExpression::BinaryExpression(std::unique_ptr<Container>&& container, const Allocator<NodeAST>& allocator)
	:container_(std::move(container)), allocator_(allocator), current_pos_(0), length_container_(container_->size())
{}

BinaryExpression::BinaryExpression(std::unique_ptr<Container>&& container, Allocator<NodeAST>&& allocator)
	: container_(std::move(container)), allocator_(std::move(allocator)), current_pos_(0), length_container_(container_->size())
{}

BinaryExpression::~BinaryExpression()
{}

NodeAST* BinaryExpression::build()
{
	NodeAST* bin_expr = allocNode(TokenType::BIN_EXPR);
	bin_expr_t(bin_expr);		/* buil abstract syntax tree */

	return bin_expr;
}

void BinaryExpression::bin_expr_t(NodeAST* root)
{
	bool isLQflage = false;
	if ( ( isId(getType(0)) || isLQ(getType(0),&isLQflage) ) && root->getLoperand() == nullptr && root->getRoperand() == nullptr )
	{
		root->setLoperand( allocNode(TokenType::TERM) );		/* bin_expr -> term; */
		term_t(root->getLoperand());
	}
	if ( isUnaryOperator(getType(0)) && root->getLoperand() != nullptr && root->getRoperand() == nullptr )
	{
		root->setToken(getToken(0));		/* PLUS | MINUS */
		next(1);

		root->setRoperand( allocNode(TokenType::BIN_EXPR) );		/* bin_expr -> term (+,-) bin_expr; */
		bin_expr_t(root->getRoperand());
	}
	if (getType(0) == TokenType::RQ && isLQflage)
	{
		next(1);
		return;
	}
	// else throw("syntax error");
}

void BinaryExpression::term_t(NodeAST* root)
{
	bool isLQflage = false;
	if ((isId(getType(0)) || isLQ(getType(0), &isLQflage)) && root->getLoperand() == nullptr && root->getRoperand() == nullptr)
	{
		root->setLoperand( allocNode(TokenType::FACT) );		/* term -> fact; */
		fact_t(root->getLoperand());
	}
	if ( isBinaryOperator(getType(0)) && root->getLoperand() != nullptr && root->getRoperand() == nullptr )
	{
		root->setToken(getToken(0));		/* STAR | SLACH */
		next(1);

		root->setRoperand( allocNode(TokenType::TERM) );		/* term -> fact (*,/) term; */
		term_t(root->getRoperand());
	}
	if (getType(0) == TokenType::RQ && isLQflage)
	{
		return;
	}
	// else throw("syntax error");
}

void BinaryExpression::fact_t(NodeAST* root)
{
	if (isId(getType(0)))
	{
		root->setToken(getToken(0));		/* id */
		next(1);
	}
	else if (getType(0) == TokenType::LQ)		/* fact -> (bin_expr); */
	{
		if (root->getLoperand() == nullptr && root->getRoperand() == nullptr)
		{
			root->setLoperand( allocNode(TokenType::BIN_EXPR) );
			bin_expr_t(root->getLoperand());
		}
		if (root->getLoperand() != nullptr && root->getRoperand() == nullptr)
		{
			root->setRoperand( allocNode(TokenType::BIN_EXPR) );
			bin_expr_t(root->getRoperand());
		}
		else
		{
			SYNTAX_ERROR("syntax error: token (\n");
		}
	}
	else
	{
		SYNTAX_ERROR("syntax error\n");
	}
}

TokenType BinaryExpression::getType(const size_t position_relative) const
{
	return getToken(position_relative)->getType();
}

Token* BinaryExpression::getToken(const size_t position_relative) const
{
	size_t position = position_relative + current_pos_;
	if (position >= length_container_)
		return nullptr;
	return container_->get(position);
}

NodeAST* BinaryExpression::allocNode(TokenType&& type)
{
	return allocator_.alloc(std::move(type));
}

NodeAST* BinaryExpression::allocNode(const TokenType& type)
{
	return allocator_.alloc(type);
}

bool BinaryExpression::isId(const TokenType& type) const
{
	for (size_t i = 0; i < SIZE_ID; i++)
	{
		if (type == idTypes[i])
			return true;
	}
	return false;
}

bool BinaryExpression::isUnaryOperator(const TokenType& type) const
{
	if (type == TokenType::ADD || type == TokenType::SUB)
		return true;
	return false;
}

bool BinaryExpression::isLQ(const TokenType& type, bool *var_flage)
{
	if (type == TokenType::LQ)
	{
		*var_flage = true;
		return true;
	}
	return false;
}

bool BinaryExpression::isBinaryOperator(const TokenType& type) const
{
	if (type == TokenType::MULT || type == TokenType::DIV)
		return true;
	return false;
}

void BinaryExpression::next(const size_t offset)
{
	current_pos_ += offset;
}

