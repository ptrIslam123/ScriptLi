#include "initialized_lists.h"
#include "expression_ast.h"

InitializedList::InitializedList(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = std::make_unique<Expression>(container, allocator, position);
}

InitializedList::InitializedList(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	expr = std::make_unique<Expression>(container, std::move(allocator), position);
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
	
}


bool InitializedList::isExpr(const TokenType&) const
{
	return false;
}

bool InitializedList::isInit_list(const TokenType&) const
{
	return false;
}

bool InitializedList::isComma(const TokenType&) const
{
	return false;
}
