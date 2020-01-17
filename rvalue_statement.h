#ifndef _RVALUE_STATEMENT_H_
#define _RVALUE_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class RvalueStatement : public AST, BaseASTFunctionality
{
public:
	RvalueStatement(Container*, const Allocator<NodeAST>&, size_t&);
	RvalueStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isExpr(const TokenType&) const;

private:
	AST* expr;
};

#endif // !_RVALUE_STATEMENT_H_
