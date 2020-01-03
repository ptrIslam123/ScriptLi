#include "fields_list.h"
#include "expression_ast.h"

FieldsListStatement::FieldsListStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	expr = std::make_unique<Expression>(container, allocator, position);
}

FieldsListStatement::FieldsListStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	expr = std::make_unique<Expression>(container, std::move(allocator), position);
}

NodeAST* FieldsListStatement::build()
{
	return nullptr;
}
