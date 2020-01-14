#ifndef _STATEMENT_H_
#define _STATEMENT_H_

#include <map>
#include "ast.h"
#include "base_ast_functionality.h"
#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class Statement : public AST, BaseASTFunctionality
{
	using AST_ptr = std::unique_ptr<AST>;
public:
	Statement(Container*, const Allocator<NodeAST>&, size_t&);
	Statement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;


private:
	bool isExistsKey(const TokenType&) const;

private:
	std::map<TokenType, AST_ptr> stmt_t;
	AST_ptr dec_;
	AST_ptr if_;
	AST_ptr while_;
	AST_ptr struct_;
	AST_ptr lvalue_;
	AST_ptr rvalue_;
	AST_ptr ret_;
};

#endif // !_STATEMENT_H_
