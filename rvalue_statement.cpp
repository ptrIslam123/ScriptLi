#include "rvalue_statement.h"
#include "expression_ast.h"

/*
	stmt -> rvalue;
	rvalue -> expr;
*/

RvalueStatement::RvalueStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = makeAST(ASTClassType::EXPR, container, allocator, position);
}

RvalueStatement::RvalueStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	expr = makeAST(ASTClassType::RVALUE, container, std::move(allocator), position);
}

NodeAST* RvalueStatement::build()
{
	return expr->build();
}

bool RvalueStatement::isExpr(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr);
	return type == TokenType::LQ || expression->isId(type);
}
