#ifndef WHILE_STATEMENT_H_
#define WHILE_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class WhileStatement : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	WhileStatement(Container*, const Allocator<NodeAST>&, size_t&);
	WhileStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isExpr(const TokenType&) const;
	bool isStmt_list(const TokenType&) const;

private:
	void while_t(NodeAST*);

private:
	AST_ptr stmt_list;
	AST_ptr expr;
};

#endif // !WHILE_STATEMENT_H_
