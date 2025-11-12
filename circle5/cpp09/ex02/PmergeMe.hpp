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

template <class T>
void	print_all(T c, T main, T pend, T nonParticipating, int level)
{
	typename T::iterator it;
	std::cout << YELLOW << "Before level " << level << ": ";
    for (it = c.begin(); it != c.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != c.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

	std::cout << YELLOW << "main: " << ": ";
	if (main.size() == 0)
		std::cout << RESET << std::endl;
    for (it = main.begin(); it != main.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != main.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

	std::cout << YELLOW << "pend: " << ": ";
	if (pend.size() == 0)
		std::cout << RESET << std::endl;
    for (it = pend.begin(); it != pend.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != pend.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

	std::cout << YELLOW << "non-participating: " << ": ";
	if (nonParticipating.size() == 0)
		std::cout << RESET << std::endl;
    for (it = nonParticipating.begin(); it != nonParticipating.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != nonParticipating.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
	std::cout << std::endl;
}

class	PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		PmergeMe(const PmergeMe& other);
		PmergeMe&		operator=(const PmergeMe &other);

		Result	mergeInsertSort(char **argv);

	private:
		size_t	jsnum[19];

		Result	load_data(char **argv);

		template <class T>
		double	sort(T &c);

		template <class T>
		bool	pair_sorting(T &c, int level);

		template <class T>
		void	init_and_insert(T &c, int level);

		template <class T>
		T		get_main(T &c, size_t group, size_t &a, size_t b);

		template <class T>
		T		get_pend(T &c, size_t group, size_t &b);

		template <class T>
		T		get_non_participating(T &c, size_t group, size_t a, size_t b);

		template <class T>
		void	reverse_merge_main_pend(T &main, T pend, size_t group, size_t jsnum_i);

		template <class T>
		void	merge_main_pend(T &main, T pend, size_t group);

		template <class T>
		void	merge_main_nonparticipating(T &main, T nonParticipating);

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
	// std::cout << "size is: " << c.size() << std::endl;
	int level = 1;
	while (pair_sorting(c, level++))
		;
	level--;
	level--;
	// std::cout << std::endl;
	while (--level)
	{
		init_and_insert(c, level);
		typename T::iterator it;
		std::cout << "size is: " << c.size() << std::endl;
		for (it = c.begin(); it != c.end(); ++it) {
			std::cout << BLUE << *it << RESET;
			if ((it + 1) != c.end())
				std::cout << ", ";
			else
				std::cout << std::endl;
		}
	}
	
	return 0;
}

template <class T>
bool	PmergeMe::pair_sorting(T &c, int level)
{
	size_t	group = std::pow(2, level);
	size_t	b = (group / 2) - 1;
	size_t	a = group - 1;

	// std::cout << "group: " << group
		// << ", b: " << b
		// << ", a: " << a << std::endl;

	// typename T::iterator it;
	// // std::cout << YELLOW << "Before level " << level << ": ";
    // for (it = c.begin(); it != c.end(); ++it) {
    //     // std::cout << BLUE << *it << RESET;
    //     if ((it + 1) != c.end())
    //         // std::cout << ", ";
    //     else
    //         // std::cout << std::endl;
    // }

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
			// std::cout << c[i + b] << " > " << c[i + a] << std::endl;
			for (j = 0; j != group / 2; ++j)
				std::swap(c[i + b - j], c[i + a - j]);
		}
	}
	return (true);
}

template <class T>
void	PmergeMe::init_and_insert(T &c, int level)
{
	size_t	group = std::pow(2, level);
	size_t	b = (group / 2) - 1;
	size_t	a = group - 1;

	// std::cout << "group: " << group
		// << ", b: " << b
		// << ", a: " << a << std::endl;
	
	T	main = get_main(c, group, a, b);
	T	pend = get_pend(c, group, b);
	T	nonParticipating = get_non_participating(c, group, a, b);

	print_all(c, main, pend, nonParticipating, level);

	merge_main_pend(main, pend, group);
	merge_main_nonparticipating(main, nonParticipating);

	// print_all(c, main, pend, nonParticipating, level);
	c = main;
}

template <class T>
T	PmergeMe::get_main(T &c, size_t group, size_t &a, size_t b)
{
	T	main;
	for (size_t i = 0; i <= b; ++i)
		main.push_back(c[i]);
	for (; a < static_cast<size_t>(c.size()); a += group)
	{
		for (size_t i = a - group/2 + 1; i <= a; ++i)
			main.push_back(c[i]);
	}
	return (main);
}

template <class T>
T	PmergeMe::get_pend(T &c, size_t group, size_t &b)
{
	T	pend;
	for (b += group; b < static_cast<size_t>(c.size()); b += group)
	{
		for (size_t i = b - group/2 + 1; i <= b; ++i)
			pend.push_back(c[i]);
	}
	return (pend);
}

template <class T>
T	PmergeMe::get_non_participating(T &c, size_t group, size_t a, size_t b)
{
	T non_participating;
	size_t i;
	if (a > b)
		i = a - group + 1;
	else
		i = b - group + 1;

	// std::cout << a << ", " << b << ", " << i <<std::endl;

	if (i == c.size())
		return (non_participating);

	for (; i < c.size(); ++i)
	{
		non_participating.push_back(c[i]);
	}
	
	// typename T::iterator it;
	// for (it = non_participating.begin(); it != non_participating.end(); ++it) {
	// 	// std::cout << BLUE << *it << RESET;
	// 	if ((it + 1) != non_participating.end())
	// 		// std::cout << ", ";
	// 	else
	// 		// std::cout << std::endl;
	// }
	return (non_participating);
}

template <class T>
void	PmergeMe::merge_main_pend(T &main, T pend, size_t group)
{
	size_t	jsnum_i = 1;
	size_t	pend_i = 0;
	size_t	bound = 0;

	pend_i = (jsnum[jsnum_i] * (group / 2)) - group / 2 - 1;
	bound = (jsnum[jsnum_i] * (group / 2)) - 1;
	while (1)
	{
		// std::cout << pend_i << ", " << bound << std::endl;

		if (bound > main.size())
			bound = main.size();
		if (pend_i >= pend.size())
		{
			reverse_merge_main_pend(main, pend, group, jsnum_i - 1);
			break ;
		}
		for (size_t i = jsnum[jsnum_i - 1]; i < jsnum[jsnum_i]; ++i)
		{
			bool inserted = false;
			for (size_t main_i = group / 2 - 1; main_i <= bound; main_i += group / 2)
			{
				// std::cout << main[main_i] << ", " << pend[pend_i] << std::endl;
				if (main_i == group / 2 - 1 && main[main_i] > pend[pend_i])
				{
					for (size_t j = 1; j <= group / 2; ++j)
						main.insert(main.begin() + j - 1, pend[pend_i - group / 2 + j]);
					inserted = true;	
					// bound += group/2;
					break ;
				}
				else if (main[main_i] > pend[pend_i])
				{
					// std::cout << "nyeeeeee" << std::endl;
					for (size_t j = group / 2; j >= 1; --j)
					{
						main.insert(main.begin() + main_i - group / 2 + 1 , pend[pend_i - group / 2 + j]);
						// std::cout << pend_i - group / 2 + j << std::endl;
					}
					inserted = true;
					// bound += group/2;
					break ;
				}
			}
			if (inserted == false)
			{
				for (size_t j = 1; j <= group / 2; ++j)
					main.insert(main.begin() + bound + j, pend[pend_i - group / 2 + j]);
			}
			pend_i -= (group / 2);
		}
		jsnum_i++;
		// std::cout << "hello";
		pend_i = (jsnum[jsnum_i] * (group / 2)) - group / 2 - 1;
		bound = ((jsnum[jsnum_i] + (jsnum[jsnum_i] - jsnum[jsnum_i - 1])) * (group / 2)) - 1;
		// std::cout << jsnum_i << ", " << pend_i << std::endl;

		// typename T::iterator it;
		// // std::cout << "size is: " << main.size() << std::endl;
		// for (it = main.begin(); it != main.end(); ++it) {
		// 	// std::cout << BLUE << *it << RESET;
		// 	if ((it + 1) != main.end())
		// 		// std::cout << ", ";
		// 	else
		// 		// std::cout << std::endl;
		// }
	}
}

template <class T>
void	PmergeMe::reverse_merge_main_pend(T &main, T pend, size_t group, size_t jsnum_i)
{
	// std::cout << "jsnum: " << jsnum[jsnum_i] << std::endl;
	size_t 	pend_i = ((jsnum[jsnum_i] + 1) * (group / 2)) - group / 2 - 1;
	// size_t 	bound = ((jsnum[jsnum_i] + 1) * (group / 2)) - 1;

	// if (bound > main.size())
		size_t bound = main.size();

	// std::cout << pend_i << ", " << bound << std::endl;
	while (pend_i < pend.size())
	{
		bool inserted = false;
		for (size_t main_i = bound - 1; main_i >= 0; main_i -= group / 2)
		{
			// std::cout << main[main_i] << ", " << pend[pend_i] << std::endl;
			if (main[main_i] < pend[pend_i])
			{
				for (size_t j = 1; j <= group / 2; ++j)
					main.insert(main.begin() + main_i + j, pend[pend_i - group / 2 + j]);

				inserted = true;
				break ;
			}
		}
		if (inserted == false)
		{
			for (size_t j = 1; j <= group / 2; ++j)
				main.insert(main.begin(), pend[pend_i - group / 2 + j]);
		}
		// typename T::iterator it;
		// // std::cout << "size is: " << main.size() << std::endl;
		// for (it = main.begin(); it != main.end(); ++it) {
		// 	// std::cout << BLUE << *it << RESET;
		// 	if ((it + 1) != main.end())
		// 		// std::cout << ", ";
		// 	else
		// 		// std::cout << std::endl;
		// }
		pend_i += (group / 2);
	}
}

template <class T>
void	PmergeMe::merge_main_nonparticipating(T &main, T nonParticipating)
{
	main.insert(main.end(), nonParticipating.begin(), nonParticipating.end());
}

#endif