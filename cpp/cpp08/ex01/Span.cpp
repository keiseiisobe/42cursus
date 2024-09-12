#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N)
: N_(N), value_(new std::vector<int>)
{
}

Span::Span(const Span& other)
: N_(other.N_), value_(new std::vector<int>(other.value_->capacity()))
{
	uninitialized_copy(other.value_->begin(), other.value_->end(), value_->begin());
}

Span&	Span::operator=(const Span& other)
{
	this->N_ = other.N_;
	delete this->value_;
	this->value_ = new std::vector<int>(other.value_->capacity());
	copy(other.value_->begin(), other.value_->end(), this->value_->begin());
	return *this;
}

Span::~Span()
{
	delete value_;
}

int	Span::operator[](int n) const
{
	return value_->at(n);
}

unsigned int	Span::getN() const
{
	return N_;
}

unsigned int	Span::getSize() const
{
	return value_->size();
}

unsigned int	Span::getCapacity() const
{
	return value_->capacity();
}

void	Span::addNumber(int n)
{
	if (value_->size() == N_)
		throw std::string("full of elements");
	value_->push_back(n);
}

unsigned int	Span::shortestSpan() const
{
	if (value_->size() > 1)
	{
		std::vector<int>	tmp = *value_;
		std::sort(tmp.begin(), tmp.end());
		std::vector<int>::iterator	first = tmp.begin();
		std::vector<int>::iterator	second = tmp.begin() + 1;
		int	shortest = *second - *first;
		for (;second != tmp.end();first++,second++)
		{
			if (*second - *first < shortest)
				shortest = *second - *first;
		}
		return shortest;
	}
	throw std::string("too few elements for shortestSpan()");
}

unsigned int	Span::longestSpan() const
{
	if (value_->size() > 1)
	{
		std::vector<int>	tmp = *value_;
		std::sort(tmp.begin(), tmp.end());
		return *(tmp.end() - 1) - *tmp.begin();
	}
	throw std::string("too few elements for longestSpan()");
}

void	Span::fillN(unsigned int n, int value)
{
	std::fill_n(back_inserter(*value_), n, value);
}

struct Incrementor
{
	int	current;
	Incrementor(int start) : current(start) {}
	int	operator()() {return current++;}
};

void	Span::generateN(unsigned int n, int start)
{
	Incrementor	inc(start);
	std::generate_n(back_inserter(*value_), n, inc);
}
