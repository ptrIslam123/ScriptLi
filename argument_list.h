#ifndef _ARGS_LIST_H_
#define _ARGS_LIST_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class ArgumentList : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	ArgumentList(Container*, const Allocator<NodeAST>&, size_t&);
	ArgumentList(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isExpr(const TokenType&) const;
	bool isRQ(const TokenType&) const;
	bool isComma(const TokenType&) const;
	bool isShapeLQ(const TokenType&) const;

private:
	void args_list_t(NodeAST*, bool LQ = false);

private:
	AST_ptr expr;
};

#endif // !_ARGS_LIST_H_
