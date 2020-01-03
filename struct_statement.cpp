#include "struct_statement.h"

StructStatement::StructStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
}

StructStatement::StructStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
}

NodeAST* StructStatement::build()
{
	return nullptr;
}

bool StructStatement::isFileds_list(const TokenType&) const
{
	return false;
}
