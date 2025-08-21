#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

template <typename T>
class	MutantStack : public std::stack<T, std::deque<T> >
{
	public:
        MutantStack();
		~MutantStack();

		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack &other);

		typedef typename std::stack<T, std::deque<T> >::container_type::iterator iterator;

		iterator	begin();
		iterator	end();

	private:

};

#include "MutantStack.tpp"

#endif