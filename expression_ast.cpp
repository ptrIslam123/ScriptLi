#include "expression_ast.h"

#define SYNTAX_ERROR(INF) throw INF

#define getLoperand root->getLoperand()
#define getRoperand root->getRoperand()

Expression::Expression(std::unique_ptr<Container>&& container, const Allocator<NodeAST>& allocator)
	:container_(std::move(container)), 
	allocator_(allocator),
	current_pos_(0), 
	length_container_(container_->size())
{}

Expression::Expression(std::unique_ptr<Container>&& container, Allocator<NodeAST>&& allocator)
	:container_(std::move(container)),
	allocator_(std::move(allocator)),
	current_pos_(0),
	length_container_(container_->size())
{}

Expression::~Expression()
{}

NodeAST* Expression::build()
{
	NodeAST* log_expr = allocNode(TokenType::LOG_EXPR);
	log_expr_t(log_expr);		/* build ast */

	return log_expr;
}

void Expression::log_expr_t(NodeAST* root, bool lq_operator)
{
	if ( (isId(getType(0)) || isLQ(getType(0)) ) &&  getLoperand == nullptr && getRoperand == nullptr)
	{
		root->setLoperand( allocNode(TokenType::COND_EXPR) );		/* log_expr -> cond_expr; */
		cond_expr_t(getLoperand);
	}
	if ( isLogOperator(getType(0)) && getLoperand != nullptr && getRoperand == nullptr )
	{
		root->setToken( getToken(0) );		/* LOP_OPCODE{ !, &&, || } */
		next(1);

		root->setRoperand( allocNode(TokenType::LOG_EXPR) );		/* log_expr -> cond_expr opcode log_expr; */
		log_expr_t(getRoperand);
	}
	if (isRQ(getType(0)) && lq_operator)
	{
		next(1);
		return;
	}
	// else throw "syntax error";
}

void Expression::cond_expr_t(NodeAST* root)
{
	if ((isId(getType(0)) || isLQ(getType(0))) && getLoperand == nullptr && getRoperand == nullptr)
	{
		root->setLoperand( allocNode(TokenType::BIN_EXPR) );		/* cond_expr -> bin_expr; */
		bin_expr_t(getLoperand);
	}
	if (isCondOperator(getType(0)) && getLoperand != nullptr && getRoperand == nullptr)
	{
		root->setToken(getToken(0));		/* COND_OPCODE{ >, >=, <, ... } */
		next(1);

		root->setRoperand(allocNode(TokenType::COND_EXPR));		/* cond_expr -> bin_expr opcode cond_expr; */
		cond_expr_t(getRoperand);
	}
	if ( isRQ(getType(0)) )
	{
		return;
	}
	// else throw "syntax error";
}

void Expression::bin_expr_t(NodeAST* root)
{
	if ((isId(getType(0)) || isLQ(getType(0))) && getLoperand == nullptr && getRoperand == nullptr)
	{
		root->setLoperand(allocNode(TokenType::TERM));		/* bin_expr -> term; */
		term_t(getLoperand);
	}
	if (isUnaryOperator(getType(0)) && getLoperand != nullptr && getRoperand == nullptr)
	{
		root->setToken(getToken(0));		/* UNARY_OPCODE{ +, - } */
		next(1);

		root->setRoperand(allocNode(TokenType::BIN_EXPR));		/* cond_expr -> bin_expr opcode cond_expr; */
		bin_expr_t(getRoperand);
	}
}

void Expression::term_t(NodeAST* root)
{
	if ((isId(getType(0)) || isLQ(getType(0))) && getLoperand == nullptr && getRoperand == nullptr)
	{
		root->setLoperand(allocNode(TokenType::FACT));		/* term -> fact; */
		fact_t(getLoperand);
	}
	if (isBinaryOperator(getType(0)) && getLoperand != nullptr && getRoperand == nullptr)
	{
		root->setToken(getToken(0));		/* BINARY_OPCODE{ *,/ } */
		next(1);

		root->setRoperand(allocNode(TokenType::TERM));		/* term -> fact opcode term; */
		term_t(getRoperand);
	}
}

void Expression::fact_t(NodeAST* root)
{
	if ( isId(getType(0)) )
	{
		root->setToken(getToken(0));		/* fact -> id; */
		next(1);
	}
	else if (isLQ(getType(0)))
	{
		next(1);
		if (getLoperand == nullptr && getRoperand == nullptr)
		{
			root->setLoperand( allocNode(TokenType::LOG_EXPR) );		/* fact -> (log_expr); */
			log_expr_t(getLoperand, true);
		}
		else if (getLoperand != nullptr && getRoperand == nullptr)
		{
			root->setRoperand(allocNode(TokenType::LOG_EXPR));		/* fact -> (log_expr); */
			log_expr_t(getLoperand, true);
		}
		else
		{
			SYNTAX_ERROR("TOKEN ERROR (\n");
		}
	}
	else
	{
		SYNTAX_ERROR("TOKEN ERROR: UNDEFINE TOKEN\n");
	}
}

TokenType Expression::getType(const size_t position) const
{
	return getToken(position)->getType();
}

Token* Expression::getToken(const size_t position_relative) const
{
	size_t position = position_relative + current_pos_;
	if (position >= length_container_)
		return nullptr;
	return container_->get(position);
}

NodeAST* Expression::allocNode(TokenType&& type)
{
	return allocator_.alloc(std::move(type));
}

NodeAST* Expression::allocNode(const TokenType& type)
{
	return allocator_.alloc(type);
}

bool Expression::isId(const TokenType& type) const
{
	for (size_t i = 0; i < SIZE_ID; i++)
	{
		if (type == idTypes[i])
			return true;
	}
	return false;
}

bool Expression::isLogOperator(const TokenType& type) const
{
	for (size_t i = 0; i < SIZE_LOG_OPERATOR; i++)
	{
		if (type == logOperators[i])
			return true;
	}
	return false;
}


bool Expression::isCondOperator(const TokenType& type) const
{
	for (size_t i = 0; i < SIZE_COND_OPERATOR; i++)
	{
		if (type == condOperators[i])
			return true;
	}
	return false;
}

bool Expression::isBinaryOperator(const TokenType& type) const
{
	if (type == TokenType::MULT || type == TokenType::DIV)
		return true;
	return false;
}

bool Expression::isUnaryOperator(const TokenType& type) const
{
	if (type == TokenType::ADD || type == TokenType::SUB)
		return true;
	return false;
}

bool Expression::isLQ(const TokenType& type) const
{
	if (type == TokenType::LQ)
	{
		return true;
	}
	return false;
}

bool Expression::isRQ(const TokenType& type) const
{
	if (type == TokenType::RQ)
	{
		return true;
	}
	return false;
}

void Expression::next(const size_t offset)
{
	current_pos_ += offset;
}
