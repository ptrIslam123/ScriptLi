#ifndef _STRUCT_STATEMENT_H_
#define _STRUCT_STATEMENT_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class StructStatement : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	StructStatement(Container*, const Allocator<NodeAST>&, size_t&);
	StructStatement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;
	bool isFileds_list(const TokenType&) const;

private:
	void struct_t(NodeAST*);

private:
	AST_ptr fields_list;
};

#endif // !_STRUCT_STATEMENT_H_
