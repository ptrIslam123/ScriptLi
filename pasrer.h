#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include "ast.h"

class Parser
{
public:
	Parser(std::unique_ptr<AST>&&);

	void run();

private:


private:
	std::unique_ptr<AST> stmt_;
};

#endif // !_PARSER_H_

