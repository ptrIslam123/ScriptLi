#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <map>
#include <iostream>
#include "token_type.h"


template<class T_, class BeenT_, class FactoryMethodT_>
class Singleton
{
public:
	Singleton(const FactoryMethodT_&);
	~Singleton();

	template<class ... Args>
	T_* getBeen(const BeenT_&, Args&& ... );

	template<class ... Args>
	T_* getBeen(BeenT_&&, Args&& ...);

private:
	bool isExistsBeenT(const BeenT_&) const;
	bool isExistsBeenT(BeenT_&&) const;
private:
	FactoryMethodT_ factoryM_;
	std::map<BeenT_, T_*> reestr;
	T_* been_;
};



template<class T_, class BeenT_, class FactoryMethodT_>
inline Singleton<T_, BeenT_, FactoryMethodT_>::Singleton(const FactoryMethodT_& makeFunction)
	:factoryM_(makeFunction), been_(nullptr)
{}

template<class T_, class BeenT_, class FactoryMethodT_>
inline Singleton<T_, BeenT_, FactoryMethodT_>::~Singleton()
{
	std::cout << "call destruct \n";
}

template<class T_, class BeenT_, class FactoryMethodT_>
inline bool Singleton<T_, BeenT_, FactoryMethodT_>::isExistsBeenT(const BeenT_& type) const
{	
	for (auto itertor = reestr.cbegin(); itertor != reestr.cend(); itertor++)
	{
		if (type == itertor->first)
		{
			return true;
		}
	}
	return false;
}

template<class T_, class BeenT_, class FactoryMethodT_>
inline bool Singleton<T_, BeenT_, FactoryMethodT_>::isExistsBeenT(BeenT_&& type) const
{
	for (auto itertor = reestr.cbegin(); itertor != reestr.cend(); itertor++)
	{
		if (type == itertor->first)
		{
			return true;
		}
	}
	return false;
}




template<class T_, class BeenT_, class FactoryMethodT_>
template<class ...Args>
inline T_* Singleton<T_, BeenT_, FactoryMethodT_>::getBeen(const BeenT_& beenType, Args&& ... args)
{
	if ( !isExistsBeenT(beenType) )
	{
		been_ = factoryM_(beenType);
		reestr[beenType] = been_;
	}
	return been_;
}

template<class T_, class BeenT_, class FactoryMethodT_>
template<class ...Args>
inline T_* Singleton<T_, BeenT_, FactoryMethodT_>::getBeen(BeenT_&& beenType, Args&& ... args)
{
	if (!isExistsBeenT(std::move(beenType)))
	{
		been_ = factoryM_(beenType);
		reestr[beenType] = been_;
	}
	return been_;
}







#endif // !_SINGLETON_H_

