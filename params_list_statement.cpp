#include "params_list_statement.h"

/*
	stmt -> (params_lsit);
	params_lsit -> word comma params_list;
*/

ParamsListStatement::ParamsListStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{}

ParamsListStatement::ParamsListStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{}

NodeAST* ParamsListStatement::build()
{
	NodeAST* params_list = allocNode(TokenType::PARAMS_LIST);
	next(1);
	params_list_t(params_list, true);
	return params_list;
}

void ParamsListStatement::params_list_t(NodeAST* root, bool LQ)
{
	if ( isWord(getType(0)) )
	{
		root->setToken(getToken(0));
		next(1);
		if ( isComma(getType(0)) )
		{
			root->setToken(getToken(0));
			next(1);
			root->setRoperand(allocNode(TokenType::PARAMS_LIST));
			params_list_t(root->getRoperand());
		}
		if (isRQ(getType(0)))
		{
			if (LQ)
			{
				next(1);
			}
		}
		else
		{
			throw "syntax error";
		}
	}
	else if ( isRQ(getType(0)) )
	{
		next(1);
	}
	else
	{
		throw "synatx erorr";
	}
}


inline bool ParamsListStatement::isWord(const TokenType& type) const
{
	return type == TokenType::WORD;
}

inline bool ParamsListStatement::isComma(const TokenType& type) const
{
	return type == TokenType::COMMA;
}

inline bool ParamsListStatement::isRQ(const TokenType& type) const
{
	return type == TokenType::RQ;
}
