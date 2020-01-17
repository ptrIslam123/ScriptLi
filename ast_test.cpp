#include "ast_test.h"

AST_Test::AST_Test(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = getBeen(ASTClassType::ARGS_LIST, container, allocator, position);
}

AST_Test::AST_Test(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = getBeen(ASTClassType::ARGS_LIST, container, allocator, position);
}

NodeAST* AST_Test::build()
{
	return expr->build();
}
