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

