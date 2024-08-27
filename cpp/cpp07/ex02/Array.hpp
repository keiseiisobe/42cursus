#pragma once

template<class T>
class	Array
{
	private:
		unsigned int	size;
		T		elem[size];
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>&);
		Array<T>&	operator=(const Array<T>&);
		~Array();
		unsigned int	size() const;
};
