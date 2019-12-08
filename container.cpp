#include "container.h"
#include "vector_tokens.h"
#include "ListTokens.h"

Container* makeContainer(const ContainerType& container_t, const size_t size_container = 0)
{
	switch (container_t)
	{
		case ContainerType::Vector : return new VectorTokens(size_container);
		case ContainerType::List: return new ListTokens(size_container);
		default :
			return nullptr;
	}
}



Container* makeContainer(ContainerType&& container_t, const size_t size_container = 0)
{
	switch (container_t)
	{
		case ContainerType::Vector: return new VectorTokens(size_container);
		case ContainerType::List: return new ListTokens(size_container);
		default:
			return nullptr;
	}
}
