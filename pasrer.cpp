#include "pasrer.h"

using AST_ptr = std::unique_ptr<AST>;
using NodeAST_ptr = AST::NodeAST_ptr;

Parser::Parser(AST_ptr& contecst_grammar)
	:contecst_grammar_(std::move(contecst_grammar))
{}

Parser::Parser(AST_ptr&& contecst_grammar)
	: contecst_grammar_(std::move(contecst_grammar))
{}

void Parser::run()
{
	// build abstract syntax tree
	contecst_grammar_->build();
	// get pointer abstract syntax tree
	header_ = std::move(contecst_grammar_->getResult());
}

NodeAST_ptr&& Parser::getHeader()
{
	return std::move(header_);
}
