#ifndef _TEST_H_
#define _TEST_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class AST_Test : public AST, BaseASTFunctionality
{
public:
	AST_Test(Container*, const Allocator<NodeAST>&, size_t&);
	AST_Test(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

private:
	AST* expr;
};

#endif // !_TEST_H_
