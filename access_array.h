#ifndef _ACCESS_ARRAY_H_
#define _ACCESS_ARRAY_H_

#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class AccessArray : public AST, BaseASTFunctionality
{
public:
	AccessArray(Container*, const Allocator<NodeAST>&, size_t&);
	AccessArray(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;

private:
	AST* rvalue;
};

#endif // !_ACCESS_ARRAY_H_
