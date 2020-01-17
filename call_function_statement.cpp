#include "call_function_statement.h"

CallFunctionStatement::CallFunctionStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	args_list = makeAST(ASTClassType::ARGS_LIST, container, allocator, position);
	rvalue = makeAST(ASTClassType::RVALUE, container, allocator, position);
}

CallFunctionStatement::CallFunctionStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, std::move(allocator), position)
{
	args_list = makeAST(ASTClassType::ARGS_LIST, container, std::move(allocator), position);
	rvalue = makeAST(ASTClassType::RVALUE, container, std::move(allocator), position);
}

NodeAST* CallFunctionStatement::build()
{
	NodeAST* call = allocNode(TokenType::CALL);
	call_t(call);
	return call;
}

void CallFunctionStatement::call_t(NodeAST* root)
{
	even(getType(0), TokenType::WORD);
	root->setLoperand(allocNode(TokenType::WORD));
	setWord_t(root->getLoperand());

	root->setRoperand(allocNode(TokenType::MATCHER));
	matcher_t(root->getRoperand());
}

void CallFunctionStatement::matcher_t(NodeAST* root)
{
	if ( isArgs_list(getType(0)) )
	{
		root->setLoperand(args_list->build());
		
		if ( isAccessArray() )
		{
			root->setRoperand(allocNode(TokenType::ACCESS_ARR));
			access_arr_t(root->getRoperand());
		}
		else if ( isAccessFields() )
		{
			root->setRoperand(allocNode(TokenType::ACCESS_FIELDS));
			access_fields_t(root->getRoperand());
		}
		else
		{
			throw "";
		}
	}
	else
	{
		throw "";
	}
}

void CallFunctionStatement::access_fields_t(NodeAST* root)
{
	if ( isPoint(getType(0)) )
	{
		setPoint_t(root);
		root->setLoperand(allocNode(TokenType::WORD));
		setWord_t(root->getLoperand());

		root->setRoperand(allocNode(TokenType::ACCESS_FIELDS));
		access_fields_t(root->getRoperand());
	}
}

void CallFunctionStatement::access_arr_t(NodeAST* root)
{
	if ( isL_Suare(getType(0)) )
	{
		root->setLoperand(rvalue->build());
		even(getType(0), TokenType::R_SQUARE, 1);
		root->setRoperand(allocNode(TokenType::ACCESS_ARR));
		access_arr_t(root->getRoperand());
	}
}

inline void CallFunctionStatement::setWord_t(NodeAST* root)
{
	root->setToken(getToken(0));	// WORD;
	next(1);
}

inline void CallFunctionStatement::setPoint_t(NodeAST* root)
{
	even(getType(0), TokenType::POINT);
	root->setToken(getToken(0));
	next(1);
}

inline bool CallFunctionStatement::isArgs_list(const TokenType& type) const
{
	return type == TokenType::LQ;
}

inline bool CallFunctionStatement::isPoint(const TokenType& type) const
{
	return type == TokenType::POINT;
}

inline bool CallFunctionStatement::isL_Suare(const TokenType& type) const
{
	return type == TokenType::L_SQUARE;
}

inline bool CallFunctionStatement::isAccessArray() const
{
	return (getType(0) == TokenType::WORD && getType(1) == TokenType::L_SQUARE);
}

inline bool CallFunctionStatement::isAccessFields() const
{
	return (getType(0) == TokenType::POINT && getType(1) == TokenType::WORD);
}