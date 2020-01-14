#include "container.h"
#include "vector_tokens.h"
#include "ListTokens.h"

#define EXCEPTION(INF)	std::cout << INF << "\n";\
						throw;					 \

Container* makeContainer(const ContainerType& container_t, const size_t size_container = 0)
{
	switch (container_t)
	{
	case ContainerType::Vector: return new VectorTokens(size_container);
	case ContainerType::List: return new ListTokens(size_container);
		default :
			EXCEPTION("undefine container type")
	}
}



Container* makeContainer(ContainerType&& container_t, const size_t size_container = 0)
{
	switch (container_t)
	{
	case ContainerType::Vector: return new VectorTokens(size_container);
	case ContainerType::List: return new ListTokens(size_container);
		default:
			EXCEPTION("undefine container type")
	}
}
