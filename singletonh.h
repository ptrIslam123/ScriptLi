#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <map>
#include <iostream>
#define DEBUG_INF

/*
	немного еще доработать нужно, для работы с чистыми указателями на функций
*/

template<class T_, class BeenT_, class FactoryMethodT_>
class Singleton
{
public:
	Singleton(const FactoryMethodT_&);
	~Singleton();

	template<class ... Args>
	T_* instance(const BeenT_&, Args&& ... );

	template<class ... Args>
	T_* instance(BeenT_&&, Args&& ...);

private:
	bool isExistsBeenT(const BeenT_&) const;
	bool isExistsBeenT(BeenT_&&) const;
private:
	std::map<BeenT_, std::unique_ptr<T_>> poolObj_;
	FactoryMethodT_ factoryM_;
	T_* been_;
};



template<class T_, class BeenT_, class FactoryMethodT_>
inline Singleton<T_, BeenT_, FactoryMethodT_>::Singleton(const FactoryMethodT_& makeFunction)
	:factoryM_(makeFunction), been_(nullptr)
{}

template<class T_, class BeenT_, class FactoryMethodT_>
inline Singleton<T_, BeenT_, FactoryMethodT_>::~Singleton()
{
#ifndef DEBUG_INF
	std::cout << "\n\t\t***|| call destruct singleton class ||***\n";
#endif // !DEBUG_INF

}


template<class T_, class BeenT_, class FactoryMethodT_>
template<class ...Args>
inline T_* Singleton<T_, BeenT_, FactoryMethodT_>::instance(const BeenT_& beenType, Args&& ... args)
{
	if ( !isExistsBeenT(beenType) )
	{
		been_ = factoryM_(beenType, std::forward<Args>(args) ... );
		poolObj_[beenType] = std::move(std::unique_ptr<T_>(been_));
		return been_;
	}
	been_ = (poolObj_[beenType]).get();
	return been_;
}

template<class T_, class BeenT_, class FactoryMethodT_>
template<class ...Args>
inline T_* Singleton<T_, BeenT_, FactoryMethodT_>::instance(BeenT_&& beenType, Args&& ... args)
{
	if (!isExistsBeenT(std::move(beenType)))
	{
		been_ = factoryM_(beenType, std::forward<Args>(args) ...);
		poolObj_[beenType] = std::move( std::unique_ptr<T_>(been_) );
		return been_;
	}
	been_ = (poolObj_[beenType]).get();
	return been_;
}



template<class T_, class BeenT_, class FactoryMethodT_>
inline bool Singleton<T_, BeenT_, FactoryMethodT_>::isExistsBeenT(const BeenT_& type) const
{
	for (auto itertor = poolObj_.cbegin(); itertor != poolObj_.cend(); itertor++)
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
	for (auto itertor = poolObj_.cbegin(); itertor != poolObj_.cend(); itertor++)
	{
		if (type == itertor->first)
		{
			return true;
		}
	}
	return false;
}

#endif // !_SINGLETON_H_

