#include <iostream>
#include "declare_statement.h"
#include "expression_ast.h"
#include "initialized_lists.h"

/*
	stmt -> dec ;
	dec  -> word eq ;
	eq   -> (expr) | {init_list};
*/

DeclareStatement::DeclareStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = std::make_unique<Expression>(container, allocator, position);
	init_list = std::make_unique<InitializedList>(container, allocator, position);
}



DeclareStatement::DeclareStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = std::make_unique<Expression>( container, std::move(allocator), position );
	init_list = std::make_unique<InitializedList>( container, std::move(allocator), position );
}

NodeAST* DeclareStatement::build()
{
	NodeAST* dec = allocNode(TokenType::DEC);		// stmt -> dec;
	dec->setToken(getToken(1));	// word
	next(2);
	dec_t(dec);
	return dec;
}

void DeclareStatement::dec_t(NodeAST* root)
{
	if ( getType(0) == TokenType::EQULLY )
	{
		root->setLoperand(allocNode(TokenType::EQULLY));
		next(1);

		if (isExpr(getType(0)))
		{
			root->setRoperand(expr->build());
		}
		else if ( isInit_list(getType(0)) )
		{
			root->setRoperand(init_list->build());
		}
		else
		{
			throw "syntax error";
		}
	}
	else
	{
		throw "syntax error";
	}
}

bool DeclareStatement::isExpr(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr.get());
	return type == TokenType::LQ || expression->isId(type);
}

bool DeclareStatement::isInit_list(const TokenType& type) const
{
	return type == TokenType::SHAPE_LQ;
}
