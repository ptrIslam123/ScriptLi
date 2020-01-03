#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include "container.h"
#include "ast.h"

class Parser
{
public:
	Parser(Container*);

	void run();
	NodeAST* getResult() const;

private:


private:
	NodeAST* header;
	std::unique_ptr<AST> stmt;
	size_t position;
};

#endif // !_PARSER_H_

