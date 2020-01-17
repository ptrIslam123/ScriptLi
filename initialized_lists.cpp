#include "initialized_lists.h"
#include "expression_ast.h"

/*
	stmt ->		{init_lis};
	init_list -> expr comma init_list 
	| {init_list} comma init_list ;
*/

InitializedList::InitializedList(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = makeAST(ASTClassType::RVALUE, container, allocator, position);
}

InitializedList::InitializedList(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	expr = makeAST(ASTClassType::RVALUE, container, std::move(allocator), position);
}

NodeAST* InitializedList::build()
{
	NodeAST* init_list = allocNode(TokenType::INIT_LIST);
	next(1);
	init_list_t(init_list, true);
	return init_list;
}

void InitializedList::init_list_t(NodeAST* root, bool isShapeLQ)
{
	if ( isExpr(getType(0)) )
	{
		expr_production(root, isShapeLQ);
	}
	else if ( isInit_list(getType(0)) )
	{
		init_list_production(root);
	}
	else
	{
		throw "syntax error";
	}
}

void InitializedList::expr_production(NodeAST* root, bool LQ)
{
	root->setLoperand(expr->build());
	if ( isComma(getType(0)) )
	{
		root->setToken(getToken(0));
		next(1);
		root->setRoperand(allocNode(TokenType::INIT_LIST));
		init_list_t(root->getRoperand());
	}
	if (isShapeRQ(getType(0)))
	{
		if (LQ)
		{
			next(1);
		}
		return;
	}
	else
	{
		throw "syntax error";
	}
}

void InitializedList::init_list_production(NodeAST* root)
{
	root->setLoperand(allocNode(TokenType::INIT_LIST));
	next(1);
	init_list_t(root->getLoperand(), true);
}



bool InitializedList::isExpr(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr);
	return type == TokenType::LQ || expression->isId(type);
}

bool InitializedList::isInit_list(const TokenType& type) const
{
	return type == TokenType::SHAPE_LQ;
}

bool InitializedList::isShapeRQ(const TokenType& type) const
{
	return type == TokenType::SHAPE_RQ;
}

bool InitializedList::isComma(const TokenType& type) const
{
	return type == TokenType::COMMA;
}
