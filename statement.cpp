#include "statement.h"
#include "if_statement.h"
#include "while_statement.h"
#include "struct_statement.h"
#include "ret_statement.h"
#include "lvalue_statement.h"
#include "rvalue_statement.h"
#include "declare_statement.h"

#define make_ast_l(class_type) std::make_unique<class_type>(container, allocator, position)
#define make_ast_r(class_type) std::make_unique<class_type>(container, std::move(allocator), position)

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
	//dec_ = make_ast_l(DeclareStatement);
	//if_ = make_ast_l(IfStatement);
	//while_ = make_ast_l(WhileStatement);
	//struct_ = make_ast_l(StructStatement);
	//lvalue_ = make_ast_l(LvalueStatement);
	//rvalue_ = make_ast_l(RvalueStatement);
	//ret_ = make_ast_l(ReturnStatement);
	stmt_t[TokenType::DEC] = make_ast_l(DeclareStatement);
	stmt_t[TokenType::IF] = make_ast_l(IfStatement);
	stmt_t[TokenType::WHILE] = make_ast_l(WhileStatement);
	stmt_t[TokenType::STRUCT] = make_ast_l(StructStatement);
	stmt_t[TokenType::LVALUE] = make_ast_l(LvalueStatement);
	stmt_t[TokenType::RVALUE] = make_ast_l(RvalueStatement);
	stmt_t[TokenType::RET] = make_ast_l(ReturnStatement);
}

Statement::Statement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, allocator, position)
{
	/*dec_ = make_ast_r(DeclareStatement);
	if_ = make_ast_r(IfStatement);
	while_ = make_ast_r(WhileStatement);
	struct_ = make_ast_r(StructStatement);
	lvalue_ = make_ast_r(LvalueStatement);
	rvalue_ = make_ast_r(RvalueStatement);
	ret_ = make_ast_r(ReturnStatement);*/
	stmt_t[TokenType::DEC] = make_ast_r(DeclareStatement);
	stmt_t[TokenType::IF] = make_ast_r(IfStatement);
	stmt_t[TokenType::WHILE] = make_ast_r(WhileStatement);
	stmt_t[TokenType::STRUCT] = make_ast_r(StructStatement);
	stmt_t[TokenType::LVALUE] = make_ast_r(LvalueStatement);
	stmt_t[TokenType::RVALUE] = make_ast_r(RvalueStatement);
	stmt_t[TokenType::RET] = make_ast_r(ReturnStatement);
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

