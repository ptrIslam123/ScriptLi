#include "access_array.h"

AccessArray::AccessArray(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	rvalue = makeAST(ASTClassType::RVALUE, container, allocator, position);
}

AccessArray::AccessArray(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	rvalue = makeAST(ASTClassType::RVALUE, container, std::move(allocator), position);
}
NodeAST* AccessArray::build()
{
	return nullptr;
}
