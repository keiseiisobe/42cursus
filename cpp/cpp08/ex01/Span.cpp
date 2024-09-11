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

unsigned int	Span::getSize() const
{
	return value_->size();
}

unsigned int	Span::getCapacity() const
{
	return value_->capacity();
}

void	Span::sort()
{
	std::sort(value_->begin(), value_->end());
}

void	Span::addNumber(int n)
{
	try
	{
		if (value_->size() == N_)
			throw std::string("full of elements");
		value_->push_back(n);
	}
	catch(std::string& err_msg)
	{
		std::cerr << Color::red << "Error: " << err_msg << std::endl;
		std::cerr << "comes from " << __FILE__ << " : " << __FUNCTION__ << "() : line " << __LINE__ << Color::reset << std::endl;
	}
}

unsigned int	Span::longestSpan() const
{
	std::vector<int>	tmp = *value_;
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}

unsigned int	Span::shortestSpan() const
{
	std::vector<int>	tmp = *value_;
	std::sort(tmp.begin(), tmp.end());
	if (tmp.size() > 1)
	{
		std::vector<int>::iterator	first = tmp.begin();
		std::vector<int>::iterator	second = tmp.begin() + 1;
		int	shortest = second - first;
		for (;second != tmp.end();first++,second++)
		{
			if (second - first < shortest)
				shortest = second - first;
		}
		return shortest;
	}
	throw std::string("too few elements for shortestSpan()");
}
