#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<class T>
typename T::iterator	easyfind(T& container, const int value)
{
	return find(container.begin(), container.end(), value);
}

#endif
