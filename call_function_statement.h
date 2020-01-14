#ifndef CALL_FUNC_STATEMENT_H_
#define CALL_FUNC_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class CallFunctionStatement : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	CallFunctionStatement(Container*, const Allocator<NodeAST>&, size_t&);
	CallFunctionStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

private:

};

#endif // !CALL_FUNC_STATEMENT_H_
