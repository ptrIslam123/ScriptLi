#include "base_ast_functionality.h"

BaseASTFunctionality::BaseASTFunctionality(Container* container, const Allocator<NodeAST>& allocator, size_t& position)
	:container_(container), allocator_(allocator), position_(position), length_(container_->size())
{}

BaseASTFunctionality::BaseASTFunctionality(Container* container, Allocator<NodeAST>&& allocator, size_t& position)
	: container_(container), allocator_(std::move(allocator)), position_(position), length_(container_->size())
{}

size_t BaseASTFunctionality::getPosition() const
{
	return position_;
}

void BaseASTFunctionality::setPosition(const size_t new_position)
{
	position_ = new_position;
}

NodeAST* BaseASTFunctionality::allocNode(TokenType&& type)
{
	return allocator_.alloc(std::move(type));
}

NodeAST* BaseASTFunctionality::allocNode(const TokenType& type)
{
	return allocator_.alloc(type);
}

TokenType BaseASTFunctionality::getType(const size_t position) const
{
	return getToken(position)->getType();
}

std::string BaseASTFunctionality::getValue(const size_t position) const
{
	return getToken(position)->getValue();
}

Token* BaseASTFunctionality::getToken(const size_t position_relative) const
{
	size_t position = position_ + position_relative;
	if (position >= length_)
		return nullptr;
	return container_->get(position);
}

void BaseASTFunctionality::next(const size_t offset)
{
	position_ += offset;
}

void BaseASTFunctionality::even(const TokenType& first_type, const TokenType& second_type, const size_t offset)
{
	if (first_type == second_type)
	{
		position_ += offset;
	}
	else
	{
		throw "syntax error: undefine token ";
	}
}

void BaseASTFunctionality::even(const TokenType& firstType, const TokenType& secondType) const
{
	if (firstType != secondType)
	{
		throw "syntax error: undefine token ";
	}
}

