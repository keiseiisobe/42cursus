#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template< class T, class C = typename std::deque<T> >
class	MutantStack : public std::stack<T, C>
{
	public:
		typedef typename C::iterator iterator;

		explicit MutantStack();
		explicit MutantStack(const MutantStack&);
		MutantStack&	operator=(const MutantStack&);
		~MutantStack();
		iterator	begin();
		iterator	end();
		const iterator	cbegin() const;
		const iterator	cend() const;
		iterator	rbegin();
		iterator	rend();
		const iterator	crbegin() const;
		const iterator	crend() const;
};

template<class T, class C>
MutantStack<T, C>::MutantStack()
{
}

template<class T, class C>
MutantStack<T, C>::MutantStack(const MutantStack& other)
{
}

template<class T, class C>
MutantStack<T, C>&	MutantStack<T, C>::operator=(const MutantStack<T, C>& other)
{
	return *this;
}

template<class T, class C>
MutantStack<T, C>::~MutantStack()
{
}

template<class T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin()
{
	return std::stack<T, C>::c.begin();
}

template<class T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end()
{
	return std::stack<T, C>::c.end();
}

template<class T, class C>
const typename MutantStack<T, C>::iterator	MutantStack<T, C>::cbegin() const
{
	return std::stack<T, C>::c.cbegin();
}

template<class T, class C>
const typename MutantStack<T, C>::iterator	MutantStack<T, C>::cend() const
{
	return std::stack<T, C>::c.cend();
}

template<class T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::rbegin()
{
	return std::stack<T, C>::c.rbegin();
}

template<class T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::rend()
{
	return std::stack<T, C>::c.rend();
}

template<class T, class C>
const typename MutantStack<T, C>::iterator	MutantStack<T, C>::crbegin() const
{
	return std::stack<T, C>::c.crbegin();
}

template<class T, class C>
const typename MutantStack<T, C>::iterator	MutantStack<T, C>::crend() const
{
	return std::stack<T, C>::c.crend();
}

#endif
