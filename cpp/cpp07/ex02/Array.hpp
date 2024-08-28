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
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>&);
		Array<T>&	operator=(const Array<T>&);
		~Array();
		unsigned int	size() const;
		class	sizeMismatch : public std::exception
		{
			public:
				void	what();
		};
};
