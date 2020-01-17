#ifndef _IF_STATEMENT_H_
#define _IF_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class IfStatement : public AST, BaseASTFunctionality
{
public:
	IfStatement(Container*, const Allocator<NodeAST>&, size_t&);
	IfStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isExpr(const TokenType&) const;
	bool isStmt_list(const TokenType&) const;
	bool isElse(const TokenType&) const;

private:
	void if_t(NodeAST*);
	void matcher(NodeAST*);

private:
	AST* stmt_list;
	AST* expr;
};

#endif // !_IF_STATEMENT_H_
