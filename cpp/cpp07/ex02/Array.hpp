#pragma once

#include <stdexcept>
#include <iostream>

template<class T>
class	Array
{
	private:
		unsigned int	sz;
		T				*elem;
		void	copy(const T *begin, const T *end, T *out);
		void	fill(T *begin, const T *end, const T value);
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>&);
		Array<T>&	operator=(const Array<T>&);
		~Array();
		const T&	operator[](unsigned int i) const;
		T&	operator[](unsigned int i);
		unsigned int	size() const;
		class	sizeMismatch : public std::exception
		{
			public:
				void	what();
		};
};
