#include "expression_ast.h"

#define SYNTAX_ERROR(INF) throw INF

#define getLoperand root->getLoperand()
#define getRoperand root->getRoperand()



/*
	stmt ->			log_expr | e;
	log_expr ->		cond_expr {&&,...} log_expr | cond_expr;
	cond_expr ->	bin_expr {>,...} cond_expr | bin_expr;
	bin_expr ->		term {+,...} bin_expr | term;
	term ->			fact {*,...} term | fact;
	fact ->			id {INT,...} | (log_expr);
*/


Expression::Expression(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position),
	allocator_(allocator)
{}

Expression::Expression(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position),
	allocator_(std::move(allocator))
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
	return type == TokenType::MULT || type == TokenType::DIV;
}

bool Expression::isUnaryOperator(const TokenType& type) const
{
	return type == TokenType::ADD || type == TokenType::SUB;
}

bool Expression::isLQ(const TokenType& type) const
{
	return type == TokenType::LQ;
}

bool Expression::isRQ(const TokenType& type) const
{
	return type == TokenType::RQ;
}

