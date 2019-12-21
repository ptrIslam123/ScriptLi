#include "node_ast.h"

using NodeAST_ptr = std::unique_ptr<NodeAST>;
using Token_ptr = std::unique_ptr<Token>;

NodeAST::NodeAST()
	:loperand_(nullptr), roperand_(nullptr), value_(nullptr), type_(TokenType::UNDEFINE)
{}

NodeAST::NodeAST(Token_ptr&& value)
	:loperand_(nullptr), roperand_(nullptr), value_(std::move(value)), type_(TokenType::UNDEFINE)
{}

void NodeAST::setType(const TokenType& type)
{
	type_ = type;
}

void NodeAST::setToken(Token_ptr&& value)
{
	value_ = std::move(value);
}

void NodeAST::setLoperand(NodeAST_ptr&& loperand)
{
	loperand_ = std::move(loperand);
}

void NodeAST::setRoperand(NodeAST_ptr&& roperand)
{
	roperand_ = std::move(roperand);
}

NodeAST_ptr* const NodeAST::getLooperand_ptr()
{
	return &loperand_;
}

NodeAST_ptr* const NodeAST::getRoperand_ptr()
{
	return &roperand_;
}

bool NodeAST::is_null_Loperand() const
{
	if (loperand_ == nullptr)
		return true;
	return false;
}

bool NodeAST::is_null_Roperand() const
{
	if (roperand_ == nullptr)
		return true;
	return false;
}

Token_ptr* const NodeAST::getToken() 
{
	return &value_;
}
