#include <iostream>
#include "declare_statement.h"
#include "expression_ast.h"
#include "initialized_lists.h"


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
	next(1);
	dec_t(dec);
	return dec;
}

void DeclareStatement::dec_t(NodeAST* root)
{
	root->setToken(getToken(0));		/* WORD; */
	next(1);
	if (getType(0) == TokenType::EQULLY)
	{
		root->setLoperand(allocNode(getType(0)));
		next(1);
		equality_t(root);
	}
}

void DeclareStatement::equality_t(NodeAST* root)
{
	if (isExpr(getType(0)))
	{
		root->setRoperand( expr->build() );
	}
	else if (isInit_list(getType(0)))
	{
		root->setRoperand( init_list->build() ); 
	}
	else
	{
		throw "syntax error(dec -> equality;)";
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
