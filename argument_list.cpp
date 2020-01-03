#include "argument_list.h"
#include "expression_ast.h"

/*
	stmt -> (args_list);
	args_list -> expr comma args_list | e;
*/

ArgumentList::ArgumentList(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = std::make_unique<Expression>(container, allocator, position);
}

ArgumentList::ArgumentList(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
	expr = std::make_unique<Expression>(container, std::move(allocator), position);
}

NodeAST* ArgumentList::build()
{
	NodeAST* args_list = allocNode(TokenType::ARGS_LIST);
	next(1);
	if (isRQ(getType(0)))
	{
		next(1);
		return args_list;
	}
	args_list_t(args_list);
	return args_list;
}

void ArgumentList::args_list_t(NodeAST* root)
{
	if ( isExpre(getType(0)) )
	{
		root->setLoperand( expr->build() );		/* args_list -> expr; (args_list -> expr comma args_list) */
		if (isRQ(getType(0)))
		{
			next(1);
			return;
		}
		isComma(getType(0), root);
		root->setRoperand(allocNode(TokenType::ARGS_LIST));
		args_list_t(root->getRoperand());
	}
	else
	{
		throw "syntax error(args_list)";
	}
}

bool ArgumentList::isExpre(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr.get());
	return type == TokenType::LQ || expression->isId(type);
}

bool ArgumentList::isRQ(const TokenType& type) const
{
	return type == TokenType::RQ;
}


inline void ArgumentList::isComma(const TokenType& type, NodeAST* root)
{
	if (type == TokenType::COMMA)
	{
		root->setToken(getToken(0));
		next(1);
	}
}
