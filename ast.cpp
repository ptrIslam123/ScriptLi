#include "singletonh.h"

#include "ast.h"
#include "expression_ast.h"
#include "rvalue_statement.h"
#include "lvalue_statement.h"
#include "declare_statement.h"
#include "define_statement.h"
#include "struct_statement.h"
#include "if_statement.h"
#include "while_statement.h"
#include "statement.h"
#include "statement_list.h"
#include "initialized_lists.h"
#include "argument_list.h"
#include "fields_list.h"
#include "ret_statement.h"
#include "params_list_statement.h"
#include "call_function_statement.h"

#include "test_token_type.h"
#include "ast_test.h"


#define allocAST_L(CLASS_AST,CONTAINER,ALLOCATOR,POSITION) return new CLASS_AST(CONTAINER, ALLOCATOR, POSITION) 
#define allocAST_R(CLASS_AST,CONTAINER,ALLOCATOR,POSITION) return new CLASS_AST(CONTAINER, std::move(ALLOCATOR), POSITION) 


auto factoryASTBeen = [](const ASTClassType& type, Container* container, const Allocator<NodeAST>& allocator, size_t& position)
{
	return makeASTunit(type, container, allocator, position);
};

static Singleton<AST, ASTClassType, decltype(factoryASTBeen)> poolBeens(factoryASTBeen);

AST* getBeen(const ASTClassType & type, Container * container, const Allocator<NodeAST>& allocator, size_t& position)
{
	return poolBeens.instance(type, container, allocator, position);
}

AST* getBeen(const ASTClassType& type, Container* container, Allocator<NodeAST>&& allocator, size_t& position)
{
	return poolBeens.instance(type, container, std::move(allocator), position);
}


AST* makeASTunit(const ASTClassType& type, Container* container, const Allocator<NodeAST>& allocator, size_t& position)
{
	switch (type)
	{
		case ASTClassType::EXPR: allocAST_L(Expression,container,allocator,position);
		case ASTClassType::RVALUE: allocAST_L(RvalueStatement,container,allocator,position);
		case ASTClassType::LVALUE: allocAST_L(LvalueStatement,container,allocator,position);
		case ASTClassType::DEC: allocAST_L(DeclareStatement,container,allocator,position);
		case ASTClassType::DEF: allocAST_L(DefineStatement,container,allocator,position);
		case ASTClassType::STRUCT: allocAST_L(StructStatement,container,allocator,position);
		case ASTClassType::IF: allocAST_L(IfStatement,container,allocator,position);
		case ASTClassType::WHILE: allocAST_L(WhileStatement,container,allocator,position);
		case ASTClassType::STMT: allocAST_L(Statement,container,allocator,position);
		case ASTClassType::STMT_LIST: allocAST_L(StatementList,container,allocator,position);
		case ASTClassType::INIT_LIST: allocAST_L(InitializedList,container,allocator,position);
		case ASTClassType::ARGS_LIST: allocAST_L(ArgumentList,container,allocator,position);
		case ASTClassType::FIELDS_LIST: allocAST_L(FieldsListStatement,container,allocator,position);
		case ASTClassType::RET: allocAST_L(ReturnStatement,container,allocator,position);
		case ASTClassType::PARAMS_LIST: allocAST_L(ParamsListStatement,container,allocator,position);
		case ASTClassType::CALL: allocAST_L(CallFunctionStatement,container,allocator,position);
		default :
			return nullptr;
	}
}

AST* makeASTunit(const ASTClassType& type, Container* container, Allocator<NodeAST>&& allocator, size_t& position)
{
	switch (type)
	{
	case ASTClassType::EXPR: allocAST_R(Expression, container, allocator, position);
	case ASTClassType::RVALUE: allocAST_R(RvalueStatement, container, allocator, position);
	case ASTClassType::LVALUE: allocAST_R(LvalueStatement, container, allocator, position);
	case ASTClassType::DEC: allocAST_R(DeclareStatement, container, allocator, position);
	case ASTClassType::DEF: allocAST_R(DefineStatement, container, allocator, position);
	case ASTClassType::STRUCT: allocAST_R(StructStatement, container, allocator, position);
	case ASTClassType::IF: allocAST_R(IfStatement, container, allocator, position);
	case ASTClassType::WHILE: allocAST_R(WhileStatement, container, allocator, position);
	case ASTClassType::STMT: allocAST_R(Statement, container, allocator, position);
	case ASTClassType::STMT_LIST: allocAST_R(StatementList, container, allocator, position);
	case ASTClassType::INIT_LIST: allocAST_R(InitializedList, container, allocator, position);
	case ASTClassType::ARGS_LIST: allocAST_R(ArgumentList, container, allocator, position);
	case ASTClassType::FIELDS_LIST: allocAST_R(FieldsListStatement, container, allocator, position);
	case ASTClassType::RET: allocAST_R(ReturnStatement, container, allocator, position);
	case ASTClassType::PARAMS_LIST: allocAST_R(ParamsListStatement, container, allocator, position);
	case ASTClassType::CALL: allocAST_R(CallFunctionStatement, container, allocator, position);
	default:
		return nullptr;
	}
}
