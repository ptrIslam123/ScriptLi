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
	args_list_t(args_list, true);
	return args_list;
}

void ArgumentList::args_list_t(NodeAST* root, bool LQ)
{
	if ( isExpr(getType(0)) )
	{
		root->setLoperand(expr->build());
		if ( isComma(getType(0)) )
		{
			root->setToken(getToken(0));
			next(1);

			root->setRoperand(allocNode(TokenType::ARGS_LIST));
			args_list_t(root->getRoperand());
		}
		if ( isRQ(getType(0)) )
		{
			if (LQ)
			{
				next(1);
			}
			return;
		}
		else 
		{
			throw "synatx error";
		}
	}
	else
	{
		throw "synatxx error";
	}
}

inline bool ArgumentList::isExpr(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr.get());
	return type == TokenType::LQ || expression->isId(type);
}

inline bool ArgumentList::isRQ(const TokenType& type) const
{
	return type == TokenType::RQ;
}

inline bool ArgumentList::isComma(const TokenType& type) const
{
	return type == TokenType::COMMA;
}

bool ArgumentList::isShapeLQ(const TokenType& type) const
{
	return type == TokenType::SHAPE_LQ;
}
