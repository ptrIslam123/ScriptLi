#ifndef _LVALUE_STATEMENT_H_
#define _LVALUE_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class LvalueStatement : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	LvalueStatement(Container*, const Allocator<NodeAST>&, size_t&);
	LvalueStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isExpr(const TokenType&) const;
	bool isWord(const TokenType&) const;
	bool isEQULLY(const TokenType&) const;
	bool isL_SQUARE(const TokenType&) const;

private:
	void access_el_t(NodeAST*, bool R_SQ = false);
	void lvalue_t(NodeAST*);
	void setWord_t(NodeAST*);
	void setEqulyy_t(NodeAST*);
	
private:
	AST_ptr rvalue;
};

#endif // !_LVALUE_STATEMENT_H_
