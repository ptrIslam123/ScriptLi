#include "pasrer.h"
//#define DEBUG_INCLUDE_FILE

#ifndef DEBUG_INCLUDE_FILE
#include "declare_statement.h"
#include "argument_list.h"
#include "initialized_lists.h"
#include "while_statement.h"
#endif // !DEBUG_INCLUDE_FILE

#include "allocator.h"
#include "node_ast.h"

Parser::Parser(Container* container)
	:position(0),
	header(nullptr),
	stmt( std::make_unique<WhileStatement>( container, Allocator<NodeAST>(), position ) )
{}


void Parser::run()
{
	header = stmt->build();
}

NodeAST* Parser::getResult() const
{
	return header;
}
