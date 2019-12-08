#ifndef _CONTAINER_H_
#define _CONTAINER_H_

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
	virtual void push_back(Token*) = 0;

};


Container* makeContainer(const ContainerType&, const size_t);
Container* makeContainer(ContainerType&&, const size_t);

#endif // !_CONTAINER_H_
