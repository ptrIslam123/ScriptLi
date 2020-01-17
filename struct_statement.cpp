#include "struct_statement.h"
#include "fields_list.h"

/*
	stmt -> struct;
	struct -> text {fields_list};
*/

StructStatement::StructStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	fields_list = makeAST(ASTClassType::FIELDS_LIST, container, allocator, position);
}

StructStatement::StructStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
	fields_list = makeAST(ASTClassType::FIELDS_LIST, container, std::move(allocator), position);
}

NodeAST* StructStatement::build()
{
	NodeAST* struct_ = allocNode(TokenType::STRUCT);
	next(1);
	even(getType(0), TokenType::WORD);
	struct_->setToken(getToken(0));
	next(1);
	struct_t(struct_);
	return struct_;
}

void StructStatement::struct_t(NodeAST* root)
{
	if ( isFileds_list(getType(0)) )
	{
		root->setLoperand(fields_list->build());
	}
	else
	{
		throw "syntaxa error";
	}
}

inline bool StructStatement::isFileds_list(const TokenType& type) const
{
	return type == TokenType::SHAPE_LQ;
}