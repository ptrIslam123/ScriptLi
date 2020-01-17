#ifndef _RET_STATEMENT_H_
#define _RET_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class ReturnStatement : public AST, BaseASTFunctionality
{
public:
	ReturnStatement(Container*, const Allocator<NodeAST>&, size_t&);
	ReturnStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

	bool isExpr(const TokenType&) const;

private:
	void ret_t(NodeAST*);

private:
	AST* expr;
};

#endif // !_RET_STATEMENT_H_
