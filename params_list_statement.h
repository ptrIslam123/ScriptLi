#ifndef _PARAMS_LIST_STATEMENT_H_
#define _PARAMS_LIST_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class ParamsListStatement : public AST, BaseASTFunctionality
{
public:
	ParamsListStatement(Container*, const Allocator<NodeAST>&, size_t&);
	ParamsListStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

private:
	void params_list_t(NodeAST*, bool LQ = false);
	bool isWord(const TokenType&) const;
	bool isComma(const TokenType&) const;
	bool isRQ(const TokenType&) const;
};

#endif // !_PARAMS_LIST_STATEMENT_H_
