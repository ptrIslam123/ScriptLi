#include "lvalue_statement.h"
#include "rvalue_statement.h"

/*
	stmt -> lvalue;
	lvalue -> word = expr |
	word [ expr ] = expr |
	word op{'++','--',...} ;
*/

LvalueStatement::LvalueStatement(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:BaseASTFunctionality(container, allocator, position)
{
	rvalue = makeAST(ASTClassType::RVALUE, container, allocator ,position);
}

LvalueStatement::LvalueStatement(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: BaseASTFunctionality(container, std::move(allocator), position)
{
	rvalue = makeAST(ASTClassType::RVALUE, container, std::move(allocator), position);
}

NodeAST* LvalueStatement::build()
{
	NodeAST* lvalue = allocNode(TokenType::LVALUE);
	lvalue->setLoperand(allocNode(TokenType::EQULLY));
	lvalue_t(lvalue->getLoperand());
	return lvalue;
}


void LvalueStatement::lvalue_t(NodeAST* root)
{
	if (isL_SQUARE(getType(1)))	// lvalue -> word [ rvalue ] = rvalue ;
	{
		root->setLoperand(allocNode(TokenType::ACCESS_ELEMENT));
		access_el_t(root->getLoperand(), true);
	}
	else if ( isWord(getType(0)) )		// lvalue -> word = expr ;
	{
		root->setLoperand(allocNode(TokenType::WORD));
		setWord_t(root->getLoperand());
		if ( isEQULLY(getType(0)) )
		{
			setEqulyy_t(root);
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

void LvalueStatement::access_el_t(NodeAST* root, bool R_SQ)
{
	even(getType(0), TokenType::WORD);
	root->setLoperand(allocNode(TokenType::WORD));
	setWord_t(root->getLoperand());
	next(1);	// next token [
	root->setRoperand(rvalue->build());		// [ rvalue ];

	even(getType(0), TokenType::R_SQUARE,1);	// next token ]
	if (isEQULLY(getType(0)))
	{
		setEqulyy_t(root);
	}
	else
	{
		throw "";
	}
}


inline void LvalueStatement::setWord_t(NodeAST* root)
{
	root->setToken(getToken(0));		// WORD;
	next(1);
}

inline void LvalueStatement::setEqulyy_t(NodeAST* root)
{
	root->setToken(getToken(0));	// COMMA;	
	next(1);
	root->setRoperand(rvalue->build());
}


inline bool LvalueStatement::isExpr(const TokenType& type) const
{
	return static_cast<RvalueStatement*>(rvalue)->isExpr(type);
}

inline bool LvalueStatement::isWord(const TokenType& type) const
{
	return type == TokenType::WORD;
}

inline bool LvalueStatement::isEQULLY(const TokenType& type) const
{
	return type == TokenType::EQULLY;
}

inline bool LvalueStatement::isL_SQUARE(const TokenType& type) const
{
	return type == TokenType::L_SQUARE;
}
