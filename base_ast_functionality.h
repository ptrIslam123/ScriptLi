#ifndef _BASE_AST_FUNCTIONALITY_H_
#define _BASE_AST_FUNCTIONALITY_H_

#include "container.h"
#include "allocator.h"
#include "node_ast.h"

class BaseASTFunctionality
{
public:
	BaseASTFunctionality(Container*, const Allocator<NodeAST>&, size_t&);
	BaseASTFunctionality(Container*, Allocator<NodeAST>&&, size_t&);

protected:
	size_t getPosition() const;
	void setPosition(const size_t);
	NodeAST* allocNode(TokenType&&);
	NodeAST* allocNode(const TokenType&);

	TokenType getType(const size_t) const;
	std::string getValue(const size_t) const;
	Token* getToken(const size_t) const;
	void next(const size_t);
	void even(const TokenType&, const TokenType&, const size_t offset = 0);

private:
	Container* container_;
	Allocator<NodeAST> allocator_;
	size_t length_;
	size_t& position_;
};

#endif // !_BASE_AST_FUNCTIONALITY_H_
