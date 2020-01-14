#ifndef _DEF_STATEMENT_H_
#define _DEF_STATEMENT_H_

#include"base_ast_functionality.h"
#include "ast.h"
#include "container.h"
#include "allocator.h"

class DefineStatement : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	DefineStatement(Container*, const Allocator<NodeAST>&, size_t&);
	DefineStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isArgs_list(const TokenType&) const;
	bool isShapeLQ(const TokenType&) const;

private:
	void def_t(NodeAST*);

private:
	AST_ptr params_list;
	AST_ptr body_func;
};

#endif // !_DEF_STATEMENT_H_
