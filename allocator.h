#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

//#define DEBUG_LOG_INF
#include "node_ast.h"
#ifndef DEBUG_LOG_INF
#include <iostream>
#endif // !DEBUG_LOG_INF

#define LOG(INF) std::cout << "\n\t***|| " << INF << " ||***\n"

template <class _Type>
class Allocator
{
public:
	Allocator(const size_t = 100);
	~Allocator();

	template <class ... _Args>
	_Type* alloc(_Args&& ... args);
	
private:
	size_t capasity_;
	size_t size_;
	_Type* array;
};


template<class _Type>
inline Allocator<_Type>::Allocator(const size_t capasity)
	:capasity_(capasity), size_(0), array(nullptr)
{}

template<class _Type>
inline Allocator<_Type>::~Allocator()
{
	if (array != nullptr)
	{
#ifndef DEBUG_LOG_INF
		LOG("call destruct");
#endif // !DEBUG_LOG_INF

		delete array;
		array = nullptr;
	}
}

template<class _Type>
template<class ..._Args>
inline _Type* Allocator<_Type>::alloc(_Args&& ...args)
{
	return new _Type(
		std::forward<_Args>(args)...
	);
}


#endif // !_ALLOCATOR_H_

