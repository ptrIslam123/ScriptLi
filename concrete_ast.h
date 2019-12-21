#ifndef _CONCRETE_AST_H_
#define _CONCRETE_AST_H_

#include "ast.h"
#include "container.h"

class BaseAST : public AST
{
public:
	using NodeAST_ptr = AST::NodeAST_ptr;
	using Container_ptr = std::unique_ptr<Container>;

	BaseAST(Container_ptr&&);

	virtual NodeAST_ptr&& getResult() override;
	virtual void build() override;

	NodeAST_ptr&& stmt_t();
	void expr_t(NodeAST_ptr*);
	void term_t(NodeAST_ptr*);
	void fact_t(NodeAST_ptr*);

private:
	TokenType getType(const size_t) const;
	std::unique_ptr<Token>&& getToken(const size_t);
	Token* get(const size_t) const;
	bool isNumber(const TokenType&) const;
	bool is_null_expr() const;
	void next(const size_t);

private:
	Container_ptr tokens_;
	NodeAST_ptr header_;
	size_t pos, length;
};

#endif // !_CONCRETE_AST_H_
