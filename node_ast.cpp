#include "node_ast.h"

NodeAST::NodeAST()
	:type_(TokenType::UNDEFINE), value_(nullptr), loperand_(nullptr), roperand_(nullptr)
{}

NodeAST::NodeAST(const TokenType& type)
	:type_(type), value_(nullptr), loperand_(nullptr), roperand_(nullptr)
{}

NodeAST* NodeAST::getLoperand()
{
	return loperand_;
}

NodeAST* NodeAST::getRoperand()
{
	return roperand_;
}

TokenType NodeAST::getType()
{
	return type_;
}

Token* NodeAST::getToken()
{
	return value_;
}

void NodeAST::setLoperand(NodeAST* loperand)
{
	loperand_ = loperand;
}

void NodeAST::setRoperand(NodeAST* roperand)
{
	roperand_ = roperand;
}

void NodeAST::setType(const TokenType& type)
{
	type_ = type;
}

void NodeAST::setToken(Token* value)
{
	value_ = value;
}
