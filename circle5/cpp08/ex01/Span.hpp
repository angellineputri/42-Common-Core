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
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		void	print(int full);

		class FullCapacityException : public std::exception
		{
			public:
				const char* what() const throw();
		};

   		class InsufficientDataException : public std::exception
		{
			public:
				const char* what() const throw();
		};     

	private:
        unsigned int        max_capacity;
        std::vector<int>    v;

};

std::ostream&	operator<<(std::ostream& out, const Span& span);

#endif