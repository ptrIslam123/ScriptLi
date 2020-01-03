#include "while_statement.h"
#include "expression_ast.h"
#include "statement_list.h"

/*
	stmt -> while (expr) {stmt_list};
*/

WhileStatement::WhileStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	stmt_list = std::make_unique<StatementList>(container, allocator, position);
	expr = std::make_unique<Expression>(container, allocator, position);
}


WhileStatement::WhileStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
	stmt_list = std::make_unique<StatementList>(container, std::move(allocator), position);
	expr = std::make_unique<Expression>(container, std::move(allocator), position);
}

NodeAST* WhileStatement::build()
{
	NodeAST* while_ = allocNode(TokenType::WHILE);
	next(1);
	while_t(while_);
	return while_;
}


void WhileStatement::while_t(NodeAST* root)
{
	if ( isExpr(getType(0)) )
	{
		root->setLoperand(expr->build());
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


bool WhileStatement::isExpr(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr.get());
	return type == TokenType::LQ || expression->isId(type);
}

bool WhileStatement::isStmt_list(const TokenType& type) const
{
	return type == TokenType::SHAPE_LQ;
}