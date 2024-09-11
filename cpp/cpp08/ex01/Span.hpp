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
		int				operator[](int n) {return value_->at(n);} // useful for Debug
		unsigned int	getSize() const; // useful for Debug
		unsigned int	getCapacity() const; // useful for Debug
		void			sort(); // useful for Debug
		void			addNumber(int n);
		unsigned int	longestSpan() const;
		unsigned int	shortestSpan() const;
};

#endif
