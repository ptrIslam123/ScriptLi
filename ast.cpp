#include "ast.h"
#include "concrete_ast.h"

std::unique_ptr<AST>&& makeAST(TypeAST&& type, std::unique_ptr<Container>&& container)
{
	switch (type)
	{
	case TypeAST::BASE_AST: return std::move(
		std::make_unique<BaseAST>( BaseAST(std::move(container)) )
		);
	}
}
