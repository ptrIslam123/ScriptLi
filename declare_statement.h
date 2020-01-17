#ifndef _DECLARE_STATEMENT_H_
#define _DECLARE_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class DeclareStatement : public AST, BaseASTFunctionality
{
public:
	DeclareStatement(Container*, const Allocator<NodeAST>&, size_t&);
	DeclareStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	void dec_t(NodeAST*);
	bool isExpr(const TokenType&) const;
	bool isInit_list(const TokenType&) const;

private:
	AST* expr;
	AST* init_list;
};

#endif // !_DECLARE_STATEMENT_H_
