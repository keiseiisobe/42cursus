#pragma once

template<typename T>
void	swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T&	min(const T& a, const T& b)
{
	if (a < b)
		return const_cast<T&>(a);
	else
		return const_cast<T&>(b);
}

template<typename T>
T&	max(const T& a, const T& b)
{
	if (a > b)
		return const_cast<T&>(a);
	else
		return const_cast<T&>(b);
}
