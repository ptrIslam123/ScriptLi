#ifndef _AST_H_
#define _AST_H_

#include <iostream>
#include "container.h"
#include "node_ast.h"

enum class TypeAST
{
	BASE_AST
};

class AST
{
public:
	using NodeAST_ptr = NodeAST::NodeAST_ptr;

	virtual NodeAST_ptr&& getResult() = 0;
	virtual void build() = 0;
};


std::unique_ptr<AST>&& makeAST(TypeAST&&, std::unique_ptr<Container>&&);

#endif // !_AST_H_
