#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template< class T, class C = typename std::deque<T> >
class	MutantStack : public std::stack<T, C>
{
	public:
		typedef typename C::iterator iterator;
		typedef typename C::reverse_iterator reverse_iterator;

		MutantStack();
		MutantStack(const MutantStack&);
		MutantStack&	operator=(const MutantStack&);
		~MutantStack();
		iterator	begin();
		iterator	end();
		reverse_iterator	rbegin();
		reverse_iterator	rend();
};

template<class T, class C>
MutantStack<T, C>::MutantStack()
: std::stack<T, C>()
{
}

template<class T, class C>
MutantStack<T, C>::MutantStack(const MutantStack& other)
: std::stack<T, C>(other)
{
}

template<class T, class C>
MutantStack<T, C>&	MutantStack<T, C>::operator=(const MutantStack<T, C>& other)
{
	std::stack<T, C>::operator=(other);
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
typename MutantStack<T, C>::reverse_iterator	MutantStack<T, C>::rbegin()
{
	return std::stack<T, C>::c.rbegin();
}

template<class T, class C>
typename MutantStack<T, C>::reverse_iterator	MutantStack<T, C>::rend()
{
	return std::stack<T, C>::c.rend();
}

#endif
