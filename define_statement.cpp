#include "define_statement.h"

DefineStatement::DefineStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
}

DefineStatement::DefineStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
}

NodeAST* DefineStatement::build()
{
	return nullptr;
}
