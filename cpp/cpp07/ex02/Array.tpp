#include "Array.hpp"

template<class T>
Array<T>::Array()
	: size(1)
{
	for (unsigned int i = 0;i < size;i++)
	{
		elem[i] = 0;
	}
}

template<class T>
Array::Array(unsigned int n)
	: size(n)
{
	for (unsigned int i = 0;i < size;i++)
	{
		elem[i] = 0;
	}
}

template<class T>
Array::Array(const Array<T>& other)
	: size(other.size)
{
	for (size_t i = 0;i < size;i++)
	{
		elem[i] = other.elem[i];
	}
}

template<class T>
Array&	Array::operator=(const Array& other)
{
	if (size != other.size)
		std::cout << "Debug: the size of each array is not same. Copy assignment failed." << std::endl;
	else
	{
		for (size_t i = 0;i < size;i++)
		{
			elem[i] = other.elem[i];
		}
	}
	return *this;
}

template<class T>
Array::~Array()
{
}

template<class T>
unsigned int	Array::size() const
{
	return size;
}
