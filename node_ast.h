#ifndef _NODE_AST_H_
#define _NODE_AST_H_

#include "token_type.h"
#include "token.h"

struct NodeAST
{
public:
	NodeAST();
	NodeAST(const TokenType&);

	NodeAST* getLoperand();
	NodeAST* getRoperand();
	TokenType getType();
	Token* getToken();

	void setLoperand(NodeAST*);
	void setRoperand(NodeAST*);
	void setType(const TokenType&);
	void setToken(Token*);

private:
	NodeAST* loperand_;
	NodeAST* roperand_;
	TokenType type_;
	Token* value_;
};

#endif // !_NODE_AST_H_
