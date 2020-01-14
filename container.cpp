#include "container.h"
#include "vector_tokens.h"
#include "ListTokens.h"

#define EXCEPTION(INF)	std::cout << INF << "\n";\
						throw;					 \

std::unique_ptr<Container>&& makeContainer(const ContainerType& container_t, const size_t size_container = 0)
{
	switch (container_t)
	{
	case ContainerType::Vector : return std::make_unique<VectorTokens>(size_container);
	case ContainerType::List: return std::make_unique<ListTokens>(size_container);
		default :
			EXCEPTION("undefine container type")
	}
}



std::unique_ptr<Container>&& makeContainer(ContainerType&& container_t, const size_t size_container = 0)
{
	switch (container_t)
	{
	case ContainerType::Vector: return std::make_unique<VectorTokens>(size_container);
	case ContainerType::List: return std::make_unique<ListTokens>(size_container);
		default:
			EXCEPTION("undefine container type")
	}
}
