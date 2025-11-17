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
#include <vector>
#include <math.h>
#include <limits.h>
#include <sys/time.h>

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
	int					size;
	int					vComparison;
	int					dqComparison;
};

class PmergeMe
{
    public:
        PmergeMe();
		~PmergeMe();

		PmergeMe(const PmergeMe& other);
		PmergeMe&		operator=(const PmergeMe &other);

		Result	        mergeInsertSort(char **argv);

        static void     print_result(Result res);

    private:
        size_t	jsnum[19];

        Result	load_data(char **argv);

        // vector
		void	                sort(std::vector<int> &c, int &comparison);
        bool	                pair_sorting(std::vector<int> &c, int level, int &comparison);
        void	                init_and_insert(std::vector<int> &c, int level, int &comparison);

		void	                merge_main_pend(std::vector<int> &main, std::vector<int> pend, size_t group, int &comparison, std::vector<int> &a, std::vector<int> &b);
		void	                merge_main_nonparticipating(std::vector<int> &main, std::vector<int> nonParticipating);

        int                     binary_insert(size_t group, std::vector<int> &main, int n, int lower, int upper, int &comparison);
        void                    insert_and_update(size_t group, std::vector<int> &main, std::vector<int> &pend, int ib, int pos, std::vector<int> &a, std::vector<int> &b);

		std::vector<int> 		get_main(std::vector<int> &c, size_t group, size_t &a, size_t b);
		std::vector<int> 		get_pend(std::vector<int> &c, size_t group, size_t &b);
		std::vector<int> 		get_non_participating(std::vector<int> &c, size_t group, size_t a, size_t b);
    
        std::vector<int>        get_a_indexes(std::vector<int> &main, size_t group);
        std::vector<int>        get_b_indexes(std::vector<int> &pend, size_t group);

        // deque
        void	                sort(std::deque<int> &c, int &comparison);
        bool	                pair_sorting(std::deque<int> &c, int level, int &comparison);
        void	                init_and_insert(std::deque<int> &c, int level, int &comparison);

		void	                merge_main_pend(std::deque<int> &main, std::deque<int> pend, size_t group, int &comparison, std::deque<int> &a, std::deque<int> &b);
		void	                merge_main_nonparticipating(std::deque<int> &main, std::deque<int> nonParticipating);

        int                     binary_insert(size_t group, std::deque<int> &main, int n, int lower, int upper, int &comparison);
        void                    insert_and_update(size_t group, std::deque<int> &main, std::deque<int> &pend, int ib, int pos, std::deque<int> &a, std::deque<int> &b);

		std::deque<int> 		get_main(std::deque<int> &c, size_t group, size_t &a, size_t b);
		std::deque<int> 		get_pend(std::deque<int> &c, size_t group, size_t &b);
		std::deque<int> 		get_non_participating(std::deque<int> &c, size_t group, size_t a, size_t b);
    
        std::deque<int>         get_a_indexes(std::deque<int> &main, size_t group);
        std::deque<int>         get_b_indexes(std::deque<int> &pend, size_t group);

        int		                safer_stoi(const std::string &str);

		class invalidArgumentException : public std::exception
		{
			public:
				const char* what() const throw();
		};

} ;

#include "PmergeMe.tpp"

#endif