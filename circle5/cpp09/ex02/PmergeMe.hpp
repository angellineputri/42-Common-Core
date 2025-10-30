#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <map>
#include <algorithm>
#include <stack>
#include <sstream>
#include <limits> 

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

struct Result
{
	std::vector<int> 	before;
	std::vector<int>	v;
	std::deque<int>		dq;
	double				vTime;
	double				dqTime;
};

class	PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		PmergeMe(const PmergeMe& other);
		PmergeMe&		operator=(const PmergeMe &other);

		Result	mergeInsertSort(char **argv);

	private:
		Result	load_data(char **argv);

		template <class T>
		double	sort(T &c);

		template <class T>
		bool	pair_sorting(T &c, int level);

		int		safer_stoi(const std::string &str);

		class invalidArgumentException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

template <class T>
double	PmergeMe::sort(T &c)
{
	int level = 1;
	while (pair_sorting(c, level++))
		;
	return 0;
}

template <class T>
bool	PmergeMe::pair_sorting(T &c, int level)
{
	size_t	group = std::pow(2, level);
	size_t	b = (group / 2) - 1;
	size_t	a = group - 1;

	std::cout << "group: " << group
		<< ", b: " << b
		<< ", a: " << a << std::endl;

	typename T::iterator it;
	std::cout << YELLOW << "Before level " << level << ": ";
    for (it = c.begin(); it != c.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != c.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

	if (c.size() < group)
		return false;

	for (size_t i = 0; i < static_cast<size_t>(c.size()); i += group)
	{
		size_t j = i;
		while (j < static_cast<size_t>(c.size()) && j - i != group)
			j++;
		if (j - i != group)
			break ;
		if (c[i + b] > c[i + a])
		{
			std::cout << c[i + b] << " > " << c[i + a] << std::endl;
			for (j = 0; j != group / 2; ++j)
			{
				std::swap(c[i + b - j], c[i + a - j]);
			}
		}
	}
	return (true);
}


#endif