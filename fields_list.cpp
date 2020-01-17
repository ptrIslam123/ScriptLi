#include "fields_list.h"
#include "declare_statement.h"

/*
	stmt -> {fields_list};
	fields_lsit -> dec comma fields_list | e;
*/

FieldsListStatement::FieldsListStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	dec = makeAST(ASTClassType::DEC, container, allocator, position);
}

FieldsListStatement::FieldsListStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	dec = makeAST(ASTClassType::DEC, container, allocator, position);
}

NodeAST* FieldsListStatement::build()
{
	NodeAST* fields_list = allocNode(TokenType::FIELDS_LIST);
	next(1);
	fields_list_t(fields_list, true);
	return fields_list;
}


void FieldsListStatement::fields_list_t(NodeAST* root, bool ShapeLQ)
{
	if ( isDec(getType(0)) )
	{
		root->setLoperand(dec->build());
		if ( isComma(getType(0)) )
		{
			root->setToken(getToken(0));
			next(1);
			root->setRoperand(allocNode(TokenType::FIELDS_LIST));
			fields_list_t(root->getRoperand());
		}
		if ( isShapeRQ(getType(0)) )
		{
			if (ShapeLQ)
			{
				next(1);
			}
			return;
		}
		else
		{
			throw "synatx error";
		}
	}
	else
	{
		throw "synatx error";
	}
}

inline bool FieldsListStatement::isShapeRQ(const TokenType& type) const
{
	return type == TokenType::SHAPE_RQ;
}

inline bool FieldsListStatement::isComma(const TokenType& type) const
{
	return type == TokenType::COMMA;
}

inline bool FieldsListStatement::isDec(const TokenType& type) const
{
	return type == TokenType::DEC;
}
