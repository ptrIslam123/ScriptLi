#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <iostream>
#include "token.h"

enum class ContainerType
{
	List,
	Vector,
	ForwandList,
	Set
};

class Container
{
public:
	virtual ContainerType getType() const = 0;
	virtual size_t size() const = 0;
	virtual void push_back(Token*) = 0;
	virtual void insert(const size_t, Token*) = 0;
	virtual Token* get(const size_t) = 0;
	virtual std::unique_ptr<Token>&& getToken(const size_t) = 0;
	virtual void remove(const size_t) = 0;
	virtual void clear() = 0;

};


Container* makeContainer(const ContainerType&, const size_t);
Container* makeContainer(ContainerType&&, const size_t);

#endif // !_CONTAINER_H_
