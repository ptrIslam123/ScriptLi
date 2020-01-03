#ifndef _FILEDS_LIS_STATEMENT_H_
#define _FILEDS_LIS_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class FieldsListStatement : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	FieldsListStatement(Container*, const Allocator<NodeAST>&, size_t&);
	FieldsListStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

private:

private:
	AST_ptr expr;
};

#endif // !_FILEDS_LIS_STATEMENT_H_
