#ifndef CALL_FUNC_STATEMENT_H_
#define CALL_FUNC_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class CallFunctionStatement : public AST, BaseASTFunctionality
{
public:
	CallFunctionStatement(Container*, const Allocator<NodeAST>&, size_t&);
	CallFunctionStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

private:
	bool isArgs_list(const TokenType&) const;
	bool isPoint(const TokenType&) const;
	bool isL_Suare(const TokenType&) const;
	bool isAccessArray() const;
	bool isAccessFields() const;

	void call_t(NodeAST*);
	void matcher_t(NodeAST*);
	void setWord_t(NodeAST*);
	void setPoint_t(NodeAST*);

	void access_arr_t(NodeAST*);
	void access_fields_t(NodeAST*);

private:
	AST* args_list;
	AST* rvalue;
};

#endif // !CALL_FUNC_STATEMENT_H_
