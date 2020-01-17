#include "if_statement.h"
#include "expression_ast.h"
#include "statement_list.h"

/*
	stmt -> if;
	if -> (expr) matcher;
	matcher -> stmt_list | stmt_list else matcher;
*/

IfStatement::IfStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = makeAST(ASTClassType::RVALUE, container, allocator, position);
	stmt_list = makeAST(ASTClassType::STMT_LIST, container, allocator, position);
}

IfStatement::IfStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	expr = makeAST(ASTClassType::RVALUE, container, std::move(allocator), position);
	stmt_list = makeAST(ASTClassType::STMT_LIST, container, std::move(allocator), position);
}

NodeAST* IfStatement::build()
{
	NodeAST* if_ = allocNode(TokenType::IF);
	next(1);
	if_t(if_);
	return if_;
}

void IfStatement::if_t(NodeAST* root)
{
	if ( isExpr(getType(0)) )
	{
		root->setLoperand(expr->build());
		root->setRoperand(allocNode(TokenType::MATCHER));
		matcher(root->getRoperand());
	}
	else
	{
		throw "syntax error";
	}
}

void IfStatement::matcher(NodeAST* root)
{
	if ( isStmt_list(getType(0)) )
	{
		root->setLoperand(stmt_list->build());
	}
	if ( root->getLoperand() != nullptr && isElse(getType(0)) )
	{
		root->setToken(getToken(0));
		next(1);
		if ( isStmt_list(getType(0)) )
		{
			root->setRoperand(stmt_list->build());
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

inline bool IfStatement::isExpr(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr);
	return type == TokenType::LQ || expression->isId(type);
}

inline bool IfStatement::isStmt_list(const TokenType& type) const
{
	return type == TokenType::SHAPE_LQ;
}

inline bool IfStatement::isElse(const TokenType& type) const
{
	return type == TokenType::ELSE;
}
