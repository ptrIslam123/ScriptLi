#include "pasrer.h"
//#define DEBUG_INCLUDE_FILE

#ifndef DEBUG_INCLUDE_FILE
#include "declare_statement.h"
#include "define_statement.h"
#include "argument_list.h"
#include "initialized_lists.h"
#include "while_statement.h"
#include "if_statement.h"
#include "statement_list.h"
#include "statement.h"
#include "struct_statement.h"
#include "ret_statement.h"
#include "rvalue_statement.h"
#include "lvalue_statement.h"
#endif // !DEBUG_INCLUDE_FILE

#include "allocator.h"
#include "node_ast.h"

Parser::Parser(Container* container)
	:position(0),
	header(nullptr)
{}


void Parser::run()
{
	//header = stmt->build();
}

NodeAST* Parser::getResult() const
{
	return header;
}
