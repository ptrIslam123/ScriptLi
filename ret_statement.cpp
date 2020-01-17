#include "ret_statement.h"
#include "expression_ast.h"

/*
	stmt -> return (expr) ;
*/

ReturnStatement::ReturnStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = makeAST(ASTClassType::RVALUE, container, allocator, position);
}

ReturnStatement::ReturnStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	expr = makeAST(ASTClassType::RVALUE, container, std::move(allocator), position);
}

NodeAST* ReturnStatement::build()
{
	NodeAST* ret = allocNode(TokenType::RET);
	next(1);
	ret_t(ret);
	return ret;
}

bool ReturnStatement::isExpr(const TokenType& type) const
{
	auto expression = static_cast<Expression*>(expr);
	return type == TokenType::LQ || expression->isId(type);
}

void ReturnStatement::ret_t(NodeAST* root)
{
	if ( isExpr(getType(0)) )
	{
		root->setLoperand(expr->build());
	}
	else
	{
		throw "synatx error";
	}
}
