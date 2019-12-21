#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include "ast.h"
#include "node_ast.h"

class Parser
{
public:
	using AST_ptr = std::unique_ptr<AST>;
	using NodeAST_ptr = AST::NodeAST_ptr;

	Parser(AST_ptr&);
	Parser(AST_ptr&&);

	void run();
	NodeAST_ptr&& getHeader();

private:
	AST_ptr contecst_grammar_;
	NodeAST_ptr header_;
};

#endif // !_PARSER_H_

