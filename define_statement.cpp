#include "define_statement.h"
#include "params_list_statement.h"
#include "statement_list.h"

/*
	stmt -> def;
	def -> (params_lsit) {body_func};
*/

DefineStatement::DefineStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	params_list = std::make_unique<ParamsListStatement>(container, allocator, position);
	body_func = std::make_unique<StatementList>(container, allocator, position);
}

DefineStatement::DefineStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	params_list = std::make_unique<ParamsListStatement>(container, std::move(allocator), position);
	body_func = std::make_unique<StatementList>(container, std::move(allocator), position);
}

NodeAST* DefineStatement::build()
{
	NodeAST* def = allocNode(TokenType::DEF);
	next(1);
	even(getType(0), TokenType::WORD);
	def->setToken(getToken(0));
	next(1);
	def_t(def);
	return def;
}



void DefineStatement::def_t(NodeAST* root)
{
	if ( isArgs_list(getType(0)) )
	{
		root->setLoperand(params_list->build());
		if ( isShapeLQ(getType(0)) )
		{
			root->setRoperand(body_func->build());
		}
		else
		{
			throw "syntax error";
		}
	}
	else
	{
		throw "syntax error";
	}
}

inline bool DefineStatement::isArgs_list(const TokenType& type) const
{
	return type == TokenType::LQ;
}

inline bool DefineStatement::isShapeLQ(const TokenType& type) const
{
	return type == TokenType::SHAPE_LQ;
}
