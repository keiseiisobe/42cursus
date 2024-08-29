#include "Array.hpp"

template<class T>
Array<T>::Array()
	: sz(1), elem(new T[1])
{
	elem[0] = 0;
}

template<class T>
Array<T>::Array(unsigned int n)
	: sz(n), elem(new T[n])
{
	fill(elem, elem + n, 0);
}

template<class T>
Array<T>::Array(const Array<T>& other)
	: sz(other.sz), elem(new T[other.sz])
{
	copy(other.elem, other.elem + other.sz, this->elem);
}

template<class T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (sz != other.sz)
		throw sizeMismatch();
	copy(other.elem, other.elem + other.sz, this->elem);
	return *this;
}

template<class T>
Array<T>::~Array()
{
	delete[] elem;
}

template<class T>
const T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= sz)
		throw std::exception();
	return elem[i];
}

template<class T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= sz)
		throw std::exception();
	return elem[i];
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
void	Array<T>::fill(T *begin, const T *end, const T value)
{
	while (begin != end)
	{
		*begin = value;
		begin++;
	}
}

template<class T>
void	Array<T>::sizeMismatch::what()
{
	std::cout << "Bad size in Array<T>::operator=" << std::endl;
}
