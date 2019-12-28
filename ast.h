#ifndef _AST_H_
#define _AST_H_

#include "node_ast.h"

class AST
{
public:
	virtual NodeAST* build() = 0;
};

#endif // !_AST_H_
