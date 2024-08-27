#pragma once

#include <cstddef>

template<class T>
void	iter(T *address, size_t length, void (*func)(T t))
{
	for (size_t i = 0;i < length;i++)
	{
		func(address[i]);
	}
}
