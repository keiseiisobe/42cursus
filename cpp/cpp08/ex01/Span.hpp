#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "color.hpp"

typedef int (*func)(void);

class	Span
{
	private:
		unsigned int	N_;
		std::vector<int>	*value_;
		Span();
	public:
		explicit Span(unsigned int N);
		Span(const Span&);
		Span&	operator=(const Span&);
		~Span();
		void			addNumber(int n);
		unsigned int	longestSpan() const;
		unsigned int	shortestSpan() const;
		void			generate(int value, unsigned int size);

		int				operator[](int n) const; // useful for Debug
		unsigned int	getSize() const; // useful for Debug
		unsigned int	getCapacity() const; // useful for Debug
		void			sort(); // useful for Debug
};

#endif
