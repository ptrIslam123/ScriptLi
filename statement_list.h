#ifndef _STATEMENT_LIST_H_
#define _STATEMENT_LIST_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class StatementList : public AST, BaseASTFunctionality
{
public:
	StatementList(Container*, const Allocator<NodeAST>&, size_t&);
	StatementList(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

private:

};

#endif // !_STATEMENT_LIST_H_
