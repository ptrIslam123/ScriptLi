#ifndef _AST_H_
#define _AST_H_

#include "node_ast.h"
#include "allocator.h"
#include "container.h"

class AST
{
public:
	virtual NodeAST* build() = 0;
};

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
	CALL
};


AST* makeASTunit(const ASTClassType&, Container*, Allocator<NodeAST>&&, size_t&);
AST* makeASTunit(const ASTClassType&, Container*, const Allocator<NodeAST>&, size_t&);

#endif // !_AST_H_
