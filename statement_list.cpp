#include "statement_list.h"
#include "statement.h"

/*
	stmt -> {stmt_list};
	stmt_list -> stmt stmt_list | stmst e;
*/

StatementList::StatementList(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	stmt = std::make_unique<Statement>(container, allocator, position);
}

StatementList::StatementList(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
	stmt = std::make_unique<Statement>(container, std::move(allocator), position);
}

NodeAST* StatementList::build()
{
	NodeAST* stmt_list = allocNode(TokenType::STMT_LIST);
	next(1);
	stmt_list_t(stmt_list);
	return stmt_list;
}

void StatementList::stmt_list_t(NodeAST* root)
{
	if ( !isShapeRQ(getType(0)) )
	{
		root->setLoperand(stmt->build());
		root->setRoperand(allocNode(TokenType::STMT_LIST));
		stmt_list_t(root->getRoperand());
	}
	else if ( isShapeRQ(getType(0)) )
	{
		next(1);
	}
	else
	{
		throw "syntax error";
	}
}

inline bool StatementList::isShapeRQ(const TokenType& type) const
{
	return type == TokenType::SHAPE_RQ;
}