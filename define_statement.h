#ifndef _DEF_STATEMENT_H_
#define _DEF_STATEMENT_H_

#include"base_ast_functionality.h"
#include "ast.h"
#include "container.h"
#include "allocator.h"

class DefineStatement : public AST, BaseASTFunctionality
{
public:
	DefineStatement(Container*, const Allocator<NodeAST>&, size_t&);
	DefineStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
private:

};

#endif // !_DEF_STATEMENT_H_
