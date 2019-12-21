#ifndef _NODE_AST_H_
#define _NODE_AST_H_

#include <iostream>
#include "token.h"

struct NodeAST
{
	using NodeAST_ptr = std::unique_ptr<NodeAST>;
	using Token_ptr = std::unique_ptr<Token>;
public:
	NodeAST();
	NodeAST(Token_ptr&&);
	
	void setType(const TokenType&);
	void setToken(Token_ptr&&);
	void setLoperand(NodeAST_ptr&&);
	void setRoperand(NodeAST_ptr&&);

	NodeAST_ptr* const getLooperand_ptr();
	NodeAST_ptr* const getRoperand_ptr();
	bool is_null_Loperand() const;
	bool is_null_Roperand() const;
	Token_ptr* const getToken();

private:
	NodeAST_ptr loperand_;
	NodeAST_ptr roperand_;
	Token_ptr value_;
	TokenType type_;
};

#endif // !_NODE_AST_H_
