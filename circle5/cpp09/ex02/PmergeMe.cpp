#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
	// std::cout << GREEN << "PmergeMe default constructor called" << RESET << std::endl;
	size_t tmp[19] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	for (int i = 0; i < 19; ++i)
		jsnum[i] = tmp[i];
}

PmergeMe::~PmergeMe()
{
	// std::cout << RED << "PmergeMe destructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	// std::cout << BLUE << "PmergeMe copy constructor called" << RESET << std::endl;
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	// std::cout << BLUE << "PmergeMe copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

Result	PmergeMe::mergeInsertSort(char **argv)
{
	Result res;
	try {
		res = load_data(argv);
	} catch(const std::exception& e) {
		throw ;
	}

	res.vComparison = 0;
	res.dqComparison = 0;

    struct timeval start, end;

    gettimeofday(&start, NULL);
	sort(res.v, res.vComparison);
	gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long usec = end.tv_usec - start.tv_usec;
    res.vTime = seconds * 1000000 + usec;

	gettimeofday(&start, NULL);
	sort(res.dq, res.dqComparison);
	gettimeofday(&end, NULL);

	seconds = end.tv_sec - start.tv_sec;
    usec = end.tv_usec - start.tv_usec;
    res.dqTime = seconds * 1000000 + usec;
	return res;
}

Result	PmergeMe::load_data(char **argv)
{
	int 	converted;
	Result	res;
	res.dqTime = 0;
	res.vTime = 0;
	std::vector<int> *before = &res.before;
	std::vector<int> *v = &res.v;
	std::deque<int> *dq = &res.dq;

	for (size_t i = 0; argv[i]; ++i) {
		std::string argStr = argv[i];
		if (argStr.empty()) 
			continue ;
		for (size_t j = 0; j < argStr.size(); ++j) {
			if (argStr[j] == '+' && j == 0)
				continue ;
			if (!isdigit(argStr[j])) 
				throw invalidArgumentException();
		}
		try {
			converted = safer_stoi(argStr);
		} catch(const std::exception& e) {
			throw ;
		}
		before->push_back(converted);
		v->push_back(converted);
		dq->push_back(converted);
	}
	res.size = v->size();
	return res;
}

void	PmergeMe::sort(std::vector<int> &c, int &comparison)
{
    int level = 1;
	while (pair_sorting(c, level++, comparison))
		;
	level--;

	while (--level)
        init_and_insert(c, level, comparison);

    return ;
}

bool	PmergeMe::pair_sorting(std::vector<int> &c, int level, int &comparison)
{
	size_t	group = std::pow(2, level);
	size_t	b = (group / 2) - 1;
	size_t	a = group - 1;

	if (c.size() < group)
		return false;

    size_t csize = static_cast<size_t>(c.size());

	for (size_t i = 0; i < csize; i += group)
	{
		size_t j = i;
		while (j < csize && j - i != group)
			j++;
		if (j - i != group)
			break ;
		comparison++;
		if (c[i + b] > c[i + a])
		{
			for (j = 0; j != group / 2; ++j)
				std::swap(c[i + b - j], c[i + a - j]);
		}
	}
	return (true);
}

void	PmergeMe::init_and_insert(std::vector<int> &c, int level, int &comparison)
{
	size_t	group = std::pow(2, level);
	size_t	ib = (group / 2) - 1;
	size_t	ia = group - 1;

	std::vector<int>	main = get_main(c, group, ia, ib);
	std::vector<int>	pend = get_pend(c, group, ib);
	std::vector<int>	nonParticipating = get_non_participating(c, group, ia, ib);

    // printc(main, "main");
    // printc(pend, "pend");
    // printc(nonParticipating, "non-participating");

    ib = (group / 2) - 1;
	ia = group - 1;

    std::vector<int>   a = get_a_indexes(main, group);
    std::vector<int>   b = get_b_indexes(pend, group);

    // printc(a, "a");
    // printc(b, "b");

	merge_main_pend(main, pend, group, comparison, a, b);
	merge_main_nonparticipating(main, nonParticipating);

	c = main;
}

int PmergeMe::binary_insert(size_t group, std::vector<int> &main, int n, int lower, int upper, int &comparison)
{
    int  pair = static_cast<int>(group) / 2;
    int  elements = (upper - lower) / pair + 1;
    int  middle = lower + ((ceil(elements / 2.0) - 1) * pair);
    // std::cout << MAGENTA << lower << ", " << middle << ", " << upper << RESET << std::endl;
    // std::cout << GREEN << pair << ", " << elements << ", " << (ceil(elements / 2.0) - 1) << RESET << std::endl;
    // std::cout << GREEN << n << std::endl;

    if (elements == 1 || upper < lower)
    {
        comparison++;
        int cmp = middle;
        if (middle < 0)
            cmp = lower;
        if (n < main[cmp])
        {
            if (middle - pair < 0)
                return (-1);
            else 
                return (middle - pair);
        }
        return (middle);
    }

    comparison++;
    if (n > main[middle])
        return (binary_insert(group, main, n, middle + pair, upper, comparison));
    else if (n < main[middle])
        return (binary_insert(group, main, n, lower, middle - pair, comparison));
    else
        return (middle);
}

void	PmergeMe::merge_main_pend(std::vector<int> &main, std::vector<int> pend, size_t group, int &comparison, std::vector<int> &a, std::vector<int> &b)
{
    size_t na = static_cast<size_t>(a[0]);
    size_t nb = b[0];

    size_t inserted = 1;
    size_t ijs = 1;
    int lowerbound = 0;
    int upperbound = 0;
    int pos;

    while (inserted < nb)
    {
        for (size_t i = jsnum[ijs]; i > jsnum[ijs - 1]; --i)
        {
            if (i > nb)
                continue ;
            lowerbound = group / 2 - 1;
            if (i > na)
                upperbound = main.size() - 1;
            else
                upperbound = a[i] - group / 2;
            pos = binary_insert(group, main, pend[abs(b[i])], lowerbound, upperbound, comparison);
            insert_and_update(group, main, pend, i, pos, a, b);
            inserted++;
        }
        ijs++;
    }
}

void    PmergeMe::insert_and_update(size_t group, std::vector<int> &main, std::vector<int> &pend, int i, int pos, std::vector<int> &a, std::vector<int> &b)
{
    int pair = static_cast<int>(group) / 2;
    int ib = abs(b[i]);

    // std::cout << pos << std::endl;
    // std::cout << ib << ", " << *(pend.begin() + ib - pair + 1) << ", " << *(pend.begin() + ib) << std::endl;
    main.insert(main.begin() + pos + 1, pend.begin() + ib - pair + 1, pend.begin() + ib + 1);
    // printc(main, "main");

    b[i] = pos + pair;

    for (int j = 1; j <= a[0]; ++j)
    {
        if (a[j] > pos)
            a[j] += pair;
    }

    // printc(a, "a");
    // printc(b, "b");
}

void	PmergeMe::merge_main_nonparticipating(std::vector<int> &main, std::vector<int> nonParticipating)
{
	main.insert(main.end(), nonParticipating.begin(), nonParticipating.end());
}

std::vector<int>	PmergeMe::get_main(std::vector<int> &c, size_t group, size_t &a, size_t b)
{
	std::vector<int>	main;
	for (size_t i = 0; i <= b; ++i)
		main.push_back(c[i]);
	for (; a < static_cast<size_t>(c.size()); a += group)
	{
		for (size_t i = a - group/2 + 1; i <= a; ++i)
			main.push_back(c[i]);
	}
	return (main);
}

std::vector<int>	PmergeMe::get_pend(std::vector<int> &c, size_t group, size_t &b)
{
	std::vector<int>	pend;
	for (b += group; b < static_cast<size_t>(c.size()); b += group)
	{
		for (size_t i = b - group/2 + 1; i <= b; ++i)
			pend.push_back(c[i]);
	}
	return (pend);
}

std::vector<int>	PmergeMe::get_non_participating(std::vector<int> &c, size_t group, size_t a, size_t b)
{
	std::vector<int> non_participating;
	size_t i;
	if (a > b)
		i = a - group + 1;
	else
		i = b - group + 1;

	if (i == c.size())
		return (non_participating);

	for (; i < c.size(); ++i)
		non_participating.push_back(c[i]);
	
	return (non_participating);
}

std::vector<int>   PmergeMe::get_a_indexes(std::vector<int> &main, size_t group)
{
    std::vector<int> a;
    
    size_t  pair = group / 2;
    size_t  mainsize = main.size();
    size_t  elements = mainsize / pair;

    a.push_back(elements - 1);
    for (size_t i = 2; i <= elements; ++i)
        a.push_back((i * pair) - 1);
    return (a);
}

std::vector<int>   PmergeMe::get_b_indexes(std::vector<int> &pend, size_t group)
{
    std::vector<int> b;

    size_t  pair = group / 2;
    size_t  pendsize = pend.size();
    size_t  elements = pendsize / pair;
    
    b.push_back(elements + 1);
    b.push_back(pair - 1);
    for (size_t i = 1; i <= elements; ++i)
        b.push_back(((i * pair) - 1) * -1);
    return (b);
}

void	PmergeMe::sort(std::deque<int>  &c, int &comparison)
{
    int level = 1;
	while (pair_sorting(c, level++, comparison))
		;
	level--;

	while (--level)
        init_and_insert(c, level, comparison);

    return ;
}

bool	PmergeMe::pair_sorting(std::deque<int>  &c, int level, int &comparison)
{
	size_t	group = std::pow(2, level);
	size_t	b = (group / 2) - 1;
	size_t	a = group - 1;

	if (c.size() < group)
		return false;

    size_t csize = static_cast<size_t>(c.size());

	for (size_t i = 0; i < csize; i += group)
	{
		size_t j = i;
		while (j < csize && j - i != group)
			j++;
		if (j - i != group)
			break ;
		comparison++;
		if (c[i + b] > c[i + a])
		{
			for (j = 0; j != group / 2; ++j)
				std::swap(c[i + b - j], c[i + a - j]);
		}
	}
	return (true);
}

void	PmergeMe::init_and_insert(std::deque<int>  &c, int level, int &comparison)
{
	size_t	group = std::pow(2, level);
	size_t	ib = (group / 2) - 1;
	size_t	ia = group - 1;

	std::deque<int> 	main = get_main(c, group, ia, ib);
	std::deque<int> 	pend = get_pend(c, group, ib);
	std::deque<int> 	nonParticipating = get_non_participating(c, group, ia, ib);

    // printc(main, "main");
    // printc(pend, "pend");
    // printc(nonParticipating, "non-participating");

    ib = (group / 2) - 1;
	ia = group - 1;

    std::deque<int>    a = get_a_indexes(main, group);
    std::deque<int>    b = get_b_indexes(pend, group);

    // printc(a, "a");
    // printc(b, "b");

	merge_main_pend(main, pend, group, comparison, a, b);
	merge_main_nonparticipating(main, nonParticipating);

	c = main;
}

int PmergeMe::binary_insert(size_t group, std::deque<int>  &main, int n, int lower, int upper, int &comparison)
{
    int  pair = static_cast<int>(group) / 2;
    int  elements = (upper - lower) / pair + 1;
    int  middle = lower + ((ceil(elements / 2.0) - 1) * pair);
    // std::cout << MAGENTA << lower << ", " << middle << ", " << upper << RESET << std::endl;
    // std::cout << GREEN << pair << ", " << elements << ", " << (ceil(elements / 2.0) - 1) << RESET << std::endl;
    // std::cout << GREEN << n << std::endl;

    if (elements == 1 || upper < lower)
    {
        comparison++;
        int cmp = middle;
        if (middle < 0)
            cmp = lower;
        if (n < main[cmp])
        {
            if (middle - pair < 0)
                return (-1);
            else 
                return (middle - pair);
        }
        return (middle);
    }

    comparison++;
    if (n > main[middle])
        return (binary_insert(group, main, n, middle + pair, upper, comparison));
    else if (n < main[middle])
        return (binary_insert(group, main, n, lower, middle - pair, comparison));
    else
        return (middle);
}

void	PmergeMe::merge_main_pend(std::deque<int>  &main, std::deque<int>  pend, size_t group, int &comparison, std::deque<int>  &a, std::deque<int>  &b)
{
    size_t na = static_cast<size_t>(a[0]);
    size_t nb = b[0];

    size_t inserted = 1;
    size_t ijs = 1;
    int lowerbound = 0;
    int upperbound = 0;
    int pos;

    while (inserted < nb)
    {
        for (size_t i = jsnum[ijs]; i > jsnum[ijs - 1]; --i)
        {
            if (i > nb)
                continue ;
            lowerbound = group / 2 - 1;
            if (i > na)
                upperbound = main.size() - 1;
            else
                upperbound = a[i] - group / 2;
            pos = binary_insert(group, main, pend[abs(b[i])], lowerbound, upperbound, comparison);
            insert_and_update(group, main, pend, i, pos, a, b);
            inserted++;
        }
        ijs++;
    }
}

void    PmergeMe::insert_and_update(size_t group, std::deque<int>  &main, std::deque<int>  &pend, int i, int pos, std::deque<int>  &a, std::deque<int>  &b)
{
    int pair = static_cast<int>(group) / 2;
    int ib = abs(b[i]);

    // std::cout << pos << std::endl;
    // std::cout << ib << ", " << *(pend.begin() + ib - pair + 1) << ", " << *(pend.begin() + ib) << std::endl;
    main.insert(main.begin() + pos + 1, pend.begin() + ib - pair + 1, pend.begin() + ib + 1);
    // printc(main, "main");

    b[i] = pos + pair;

    for (int j = 1; j <= a[0]; ++j)
    {
        if (a[j] > pos)
            a[j] += pair;
    }

    // printc(a, "a");
    // printc(b, "b");
}

void	PmergeMe::merge_main_nonparticipating(std::deque<int>  &main, std::deque<int>  nonParticipating)
{
	main.insert(main.end(), nonParticipating.begin(), nonParticipating.end());
}

std::deque<int> 	PmergeMe::get_main(std::deque<int>  &c, size_t group, size_t &a, size_t b)
{
	std::deque<int> 	main;
	for (size_t i = 0; i <= b; ++i)
		main.push_back(c[i]);
	for (; a < static_cast<size_t>(c.size()); a += group)
	{
		for (size_t i = a - group/2 + 1; i <= a; ++i)
			main.push_back(c[i]);
	}
	return (main);
}

std::deque<int> 	PmergeMe::get_pend(std::deque<int>  &c, size_t group, size_t &b)
{
	std::deque<int> 	pend;
	for (b += group; b < static_cast<size_t>(c.size()); b += group)
	{
		for (size_t i = b - group/2 + 1; i <= b; ++i)
			pend.push_back(c[i]);
	}
	return (pend);
}

std::deque<int> 	PmergeMe::get_non_participating(std::deque<int>  &c, size_t group, size_t a, size_t b)
{
	std::deque<int>  non_participating;
	size_t i;
	if (a > b)
		i = a - group + 1;
	else
		i = b - group + 1;

	if (i == c.size())
		return (non_participating);

	for (; i < c.size(); ++i)
		non_participating.push_back(c[i]);
	
	return (non_participating);
}

std::deque<int>    PmergeMe::get_a_indexes(std::deque<int>  &main, size_t group)
{
    std::deque<int>  a;
    
    size_t  pair = group / 2;
    size_t  mainsize = main.size();
    size_t  elements = mainsize / pair;

    a.push_back(elements - 1);
    for (size_t i = 2; i <= elements; ++i)
        a.push_back((i * pair) - 1);
    return (a);
}

std::deque<int>    PmergeMe::get_b_indexes(std::deque<int>  &pend, size_t group)
{
    std::deque<int>  b;

    size_t  pair = group / 2;
    size_t  pendsize = pend.size();
    size_t  elements = pendsize / pair;
    
    b.push_back(elements + 1);
    b.push_back(pair - 1);
    for (size_t i = 1; i <= elements; ++i)
        b.push_back(((i * pair) - 1) * -1);
    return (b);
}

int	PmergeMe::safer_stoi(const std::string &str) {
    char *endptr;
    long val = std::strtol(str.c_str(), &endptr, 10);

    if (*endptr != '\0' || errno == ERANGE || val > INT_MAX || val < 0)
        throw invalidArgumentException();

    return static_cast<int>(val);
}

const char* PmergeMe::invalidArgumentException::what() const throw()
{
	return ("Error: invalid argument passed, unable to sort.");
}

void    PmergeMe::print_result(Result res)
{   
    std::vector<int>::iterator it;
    std::cout << YELLOW << "Before: ";
    for (it = res.before.begin(); it != res.before.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != res.before.end())
            std::cout << ", ";
        else
            std::cout << std::endl << std::endl;
    }

    std::cout << YELLOW << "Number of comparison with std::" 
    << BLUE << "vector" << YELLOW << " is: " 
    << BLUE << res.vComparison << RESET << std::endl << std::endl;

    int prev = *res.v.begin();
    std::cout << YELLOW << "After (std::vector):  ";
    for (it = res.v.begin(); it != res.v.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if (*it < prev)
        {
            std::cout << RED << std::endl << "not sorted!" << RESET << std::endl;
            exit(1);
        }
        else
            prev = *it;
        if ((it + 1) != res.v.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
    std::cout << GREEN << "sorted!" << RESET << std::endl << std::endl;
    
    std::deque<int>::iterator itdq;
    std::cout << YELLOW << "After (std::deque):  ";

    prev = *res.dq.begin();
    for (itdq = res.dq.begin(); itdq != res.dq.end(); ++itdq) {
        std::cout << BLUE << *itdq << RESET;
        if (*itdq < prev)
        {
            std::cout << RED << std::endl << "not sorted!" << RESET << std::endl;
            exit(1);
        }
        else
            prev = *itdq;
        if ((itdq + 1) != res.dq.end())
            std::cout << ", ";
        else
            std::cout << std::endl;   
    }
    std::cout << GREEN << "sorted!" << RESET << std::endl << std::endl;

    std::cout << YELLOW << "Time to process a range of " << res.size << " elements with std::" 
        << BLUE << "vector" << YELLOW << " is: " 
        << BLUE << res.vTime << YELLOW << " us" << RESET << std::endl;
    std::cout << YELLOW << "Number of comparison with std::" 
        << BLUE << "vector" << YELLOW << " is: " 
        << BLUE << res.vComparison << RESET << std::endl << std::endl;

    std::cout << YELLOW << "Time to process a range of " << res.size << " elements with std::" 
        << BLUE << "deque" << YELLOW << " is: " 
        << BLUE << res.dqTime << YELLOW << " us" << RESET << std::endl;
    std::cout << YELLOW << "Number of comparison with std::" 
        << BLUE << "deque" << YELLOW << " is: " 
        << BLUE << res.dqComparison << RESET << std::endl;

    if (res.vTime > res.dqTime)
        std::cout << RED << "somthings wrong..." << RESET << std::endl;
}