#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "color.hpp"

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
		void			fillN(unsigned int n, int value);
		void			generateN(unsigned int n, int start);

		// useful for debug
		int				operator[](int n) const;
		unsigned int	getN() const;
		unsigned int	getSize() const;
		unsigned int	getCapacity() const;
};

#endif
