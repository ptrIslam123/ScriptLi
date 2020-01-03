#ifndef _INIT_LIST_H_
#define _INIT_LIST_H_

#include "ast.h"
#include "node_ast.h"
#include "allocator.h"
#include "base_ast_functionality.h"
#include "container.h"

class InitializedList : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	InitializedList(Container*, const Allocator<NodeAST>&, size_t&);
	InitializedList(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isExpr(const TokenType&) const;
	bool isInit_list(const TokenType&) const;
	bool isComma(const TokenType&) const;

private:
	void init_list_t(NodeAST*, bool isShapeLQ = false);

private:
	AST_ptr expr;
};

#endif // !_INIT_LIST_H_
