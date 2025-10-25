#ifndef SPAN_HPP
#define SPAN_HPP

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

class	Span
{
	public:
		Span();
		Span(unsigned int n);
		~Span();

		Span(const Span& other);
		Span&	operator=(const Span &other);

        void    addNumber(int newN);
        int     shortestSpan();
        int     longestSpan();

		void	print(int full);
		
		template <typename ContainerIterator>
		void    addRange(ContainerIterator begin, ContainerIterator end)
		{
			size_t rangeSize = std::distance(begin, end);
			if (v.size() + rangeSize > max_capacity)
				throw FullCapacityRangeException();
			v.insert(v.end(), begin, end);
		}

		class InsufficientDataException : public std::exception
		{
			public:
				const char* what() const throw();
		};  

		class FullCapacityException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FullCapacityRangeException : public std::exception
		{
			public:
				const char* what() const throw();
		};   

	private:
        unsigned int        max_capacity;
        std::vector<int>    v;

};

#endif