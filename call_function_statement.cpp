#include "call_function_statement.h"

CallFunctionStatement::CallFunctionStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
}

CallFunctionStatement::CallFunctionStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
}

NodeAST* CallFunctionStatement::build()
{
	return nullptr;
}
