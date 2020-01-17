#include "statement.h"
#include "if_statement.h"
#include "while_statement.h"
#include "struct_statement.h"
#include "ret_statement.h"
#include "lvalue_statement.h"
#include "rvalue_statement.h"
#include "declare_statement.h"

#define make_ast_l(class_type) makeAST(class_type, container, allocator, position)
#define make_ast_r(class_type) makeAST(class_type, container, std::move(allocator), position)

/*
	stmt -> dec |
	if | 
	while |
	struct |
	lvalue |
	ret |
	e;
*/

Statement::Statement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{ 
	stmt_t[TokenType::DEC] = make_ast_l(ASTClassType::DEC);
	stmt_t[TokenType::IF] = make_ast_l(ASTClassType::IF);
	stmt_t[TokenType::WHILE] = make_ast_l(ASTClassType::WHILE);
	stmt_t[TokenType::STRUCT] = make_ast_l(ASTClassType::STRUCT);
	stmt_t[TokenType::LVALUE] = make_ast_l(ASTClassType::LVALUE);
	stmt_t[TokenType::RVALUE] = make_ast_l(ASTClassType::RVALUE);
	stmt_t[TokenType::RET] = make_ast_l(ASTClassType::RET);
}

Statement::Statement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, allocator, position)
{
	stmt_t[TokenType::DEC] = make_ast_r(ASTClassType::DEC);
	stmt_t[TokenType::IF] = make_ast_r(ASTClassType::IF);
	stmt_t[TokenType::WHILE] = make_ast_r(ASTClassType::WHILE);
	stmt_t[TokenType::STRUCT] = make_ast_r(ASTClassType::STRUCT);
	stmt_t[TokenType::LVALUE] = make_ast_r(ASTClassType::LVALUE);
	stmt_t[TokenType::RVALUE] = make_ast_r(ASTClassType::RVALUE);
	stmt_t[TokenType::RET] = make_ast_r(ASTClassType::RET);
}

NodeAST* Statement::build()
{
	TokenType currentType = getType(0);
	NodeAST* stmt = allocNode(TokenType::STMT);
	if ( isExistsKey(currentType) )
	{
		auto ast = std::move(stmt_t[currentType]);
		stmt->setLoperand(ast->build());
		return stmt;
	}
	else
	{
		throw "";
	}
	return nullptr;
}

bool Statement::isExistsKey(const TokenType& type) const
{
	for (auto it = stmt_t.cbegin(); it != stmt_t.cend(); it ++)
	{
		if (type == it->first)
		{
			return true;
		}
	}
	return false;
}

