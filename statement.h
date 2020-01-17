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
public:
	Statement(Container*, const Allocator<NodeAST>&, size_t&);
	Statement(Container*, Allocator<NodeAST>&&, size_t&);

	virtual NodeAST* build() override;


private:
	bool isExistsKey(const TokenType&) const;

private:
	std::map<TokenType, AST*> stmt_t;
	AST* dec_;
	AST* if_;
	AST* while_;
	AST* struct_;
	AST* lvalue_;
	AST* rvalue_;
	AST* ret_;
};

#endif // !_STATEMENT_H_
