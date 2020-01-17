#ifndef _AST_H_
#define _AST_H_

#include "node_ast.h"
#include "allocator.h"
#include "container.h"

#define makeAST(AST_CLASS_TYPE,CONTAINER,ALLOCATOR,POSITION)														\
															getBeen(AST_CLASS_TYPE, CONTAINER, ALLOCATOR, POSITION)	\

enum class ASTClassType
{
	EXPR,
	RVALUE,
	LVALUE,
	DEC,
	DEF,
	STRUCT,
	IF,
	WHILE,
	STMT,
	STMT_LIST,
	INIT_LIST,
	ARGS_LIST,
	FIELDS_LIST,
	RET,
	PARAMS_LIST,
	CALL,
		
	AST_TEST
};

class AST
{
public:
	virtual NodeAST* build() = 0;
};

AST* getBeen(const ASTClassType& type, Container* container, const Allocator<NodeAST>& allocator, size_t& position);
AST* getBeen(const ASTClassType& type, Container* container, Allocator<NodeAST>&& allocator, size_t& position);

AST* makeASTunit(const ASTClassType& type, Container* container, const Allocator<NodeAST>& allocator, size_t& position);
AST* makeASTunit(const ASTClassType& type, Container* container, Allocator<NodeAST>&& allocator, size_t& position);




#endif // !_AST_H_
