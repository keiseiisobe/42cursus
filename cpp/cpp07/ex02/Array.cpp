



// you must change this filename to .tpp





#include "Array.hpp"

template<class T>
Array<T>::Array()
	: sz(3)
{
	T	tmp[sz];
	elem = tmp;
	for (unsigned int i = 0;i < sz;i++)
	{
		elem[i] = 0;
	}
}

template<class T>
Array<T>::Array(unsigned int n)
	: sz(n)
{
	T	tmp[sz];
	elem = tmp;
	for (unsigned int i = 0;i < sz;i++)
	{
		elem[i] = 0;
	}
}

template<class T>
Array<T>::Array(const Array<T>& other)
	: sz(other.sz)
{
	T	tmp[sz];
	elem = tmp;
	copy(other.elem, other.elem + other.sz, this->elem);
}

template<class T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (sz != other.sz)
		throw sizeMismatch();
	copy(other.elem, other.elem + other.sz, this->elem);
	return *this;
}

template<class T>
Array<T>::~Array()
{
}

template<class T>
unsigned int	Array<T>::size() const
{
	return sz;
}

template<class T>
void	Array<T>::copy(const T *begin, const T *end, T *out)
{
	while (begin != end)
	{
		*out = *begin;
		begin++;
		out++;
	}
}

template<class T>
void	Array<T>::sizeMismatch::what()
{
	std::cout << "Bad size in Array<T>::operator=" << std::endl;
}
