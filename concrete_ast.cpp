#include "concrete_ast.h"

using NodeAST_ptr = AST::NodeAST_ptr;
using Container_ptr = std::unique_ptr<Container>;

#define MAKE_NODE() std::make_unique<NodeAST>()
#define UNDEFINE_PRODUCTION(INF) std::cout << "Error: " << INF << "\n";

BaseAST::BaseAST(Container_ptr&& tokens)
	:tokens_(std::move(tokens)), header_(nullptr), length(tokens_->size()), pos(0)
{}

NodeAST_ptr&& BaseAST::getResult()
{
	return std::move(header_);
}

void BaseAST::build()
{
	header_ = std::move( stmt_t() );
}

NodeAST_ptr&& BaseAST::stmt_t()
{
	if (is_null_expr())
		return nullptr;

	NodeAST_ptr stmt = MAKE_NODE();
	stmt->setLoperand( std::move( MAKE_NODE() ) );		// stmt -> expr;
	expr_t(stmt->getLooperand_ptr());

	return std::move(stmt);
}

void BaseAST::expr_t(NodeAST_ptr* root)
{
	if ( isNumber(getType(0)) && (*root)->is_null_Loperand() && (*root)->is_null_Roperand() )
	{
		(*root)->setLoperand( std::move(MAKE_NODE()) );		// root -> term;
		term_t((*root)->getLooperand_ptr());
	}
	if (getType(0) == TokenType::ADD && !( (*root)->is_null_Loperand() ) && (*root)->is_null_Roperand())
	{
		(*root)->setType(getType(0));
		next(1);
		(*root)->setRoperand( std::move(MAKE_NODE()) );
		expr_t((*root)->getRoperand_ptr());
	}
}

void BaseAST::term_t(NodeAST_ptr* root)
{
	if (isNumber(getType(0)) && (*root)->is_null_Loperand() && (*root)->is_null_Roperand())
	{
		(*root)->setLoperand( std::move(MAKE_NODE()) );
		fact_t((*root)->getLooperand_ptr());
	}
	if (getType(0) == TokenType::MULT && !( (*root)->is_null_Loperand() ) && (*root)->is_null_Roperand())
	{
		(*root)->setType(getType(0));
		next(1);
		(*root)->setRoperand( std::move(MAKE_NODE()) );
		term_t((*root)->getRoperand_ptr());
	}
}

void BaseAST::fact_t(NodeAST_ptr* root)
{
	if (isNumber(getType(0)))
	{
		(*root)->setToken(getToken(0));
		next(1);
	}
	else
	{
		UNDEFINE_PRODUCTION("FACT_T");
	}
}

TokenType BaseAST::getType(const size_t position_relative) const
{
	return get(position_relative)->getType();
}


Token* BaseAST::get(const size_t position_relative) const
{
	size_t position = pos + position_relative;
	if (position >= length)
		return nullptr;
	return tokens_->get(position);
}

std::unique_ptr<Token>&& BaseAST::getToken(const size_t position)
{
	return std::move( tokens_->getToken(position) );
}

bool BaseAST::is_null_expr() const
{
	if (length == 0)
		return true;
	return false;
}

void BaseAST::next(const size_t offset)
{
	pos += offset;
}

bool BaseAST::isNumber(const TokenType& type) const
{
	if (type == TokenType::NUMBER_DOUBLE || type == TokenType::NUMBER_INT)
		return true;
	return false;
}
