#include "statement_list.h"

StatementList::StatementList(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
}

StatementList::StatementList(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
}

NodeAST* StatementList::build()
{
	return nullptr;
}
