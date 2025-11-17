#include "PmergeMe.hpp"

template <class T>
void	printc(T c, std::string label)
{
	typename T::iterator it;
    std::cout << YELLOW << label << ": ";
    for (it = c.begin(); it != c.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != c.end())
            std::cout << ", ";
        else
        {
            std::cout << std::endl;
            return ;
        }
    }
    std::cout << std::endl;
}

// template <class T>
// void	PmergeMe::sort(T &c, int &comparison)
// {
//     int level = 1;
// 	while (pair_sorting(c, level++, comparison))
// 		;
// 	level--;

// 	while (--level)
//         init_and_insert(c, level, comparison);

//     return ;
// }

// template <class T>
// bool	PmergeMe::pair_sorting(T &c, int level, int &comparison)
// {
// 	size_t	group = std::pow(2, level);
// 	size_t	b = (group / 2) - 1;
// 	size_t	a = group - 1;

// 	if (c.size() < group)
// 		return false;

//     size_t csize = static_cast<size_t>(c.size());

// 	for (size_t i = 0; i < csize; i += group)
// 	{
// 		size_t j = i;
// 		while (j < csize && j - i != group)
// 			j++;
// 		if (j - i != group)
// 			break ;
// 		comparison++;
// 		if (c[i + b] > c[i + a])
// 		{
// 			for (j = 0; j != group / 2; ++j)
// 				std::swap(c[i + b - j], c[i + a - j]);
// 		}
// 	}
// 	return (true);
// }

// template <class T>
// void	PmergeMe::init_and_insert(T &c, int level, int &comparison)
// {
// 	size_t	group = std::pow(2, level);
// 	size_t	ib = (group / 2) - 1;
// 	size_t	ia = group - 1;

// 	T	main = get_main(c, group, ia, ib);
// 	T	pend = get_pend(c, group, ib);
// 	T	nonParticipating = get_non_participating(c, group, ia, ib);

//     // printc(main, "main");
//     // printc(pend, "pend");
//     // printc(nonParticipating, "non-participating");

//     ib = (group / 2) - 1;
// 	ia = group - 1;

//     T   a = get_a_indexes(main, group);
//     T   b = get_b_indexes(pend, group);

//     // printc(a, "a");
//     // printc(b, "b");

// 	merge_main_pend(main, pend, group, comparison, a, b);
// 	merge_main_nonparticipating(main, nonParticipating);

// 	c = main;
// }

// template <class T>
// int PmergeMe::binary_insert(size_t group, T &main, int n, int lower, int upper, int &comparison)
// {
//     int  pair = static_cast<int>(group) / 2;
//     int  elements = (upper - lower) / pair + 1;
//     int  middle = lower + ((ceil(elements / 2.0) - 1) * pair);
//     // std::cout << MAGENTA << lower << ", " << middle << ", " << upper << RESET << std::endl;
//     // std::cout << GREEN << pair << ", " << elements << ", " << (ceil(elements / 2.0) - 1) << RESET << std::endl;
//     // std::cout << GREEN << n << std::endl;

//     if (elements == 1 || upper < lower)
//     {
//         comparison++;
//         int cmp = middle;
//         if (middle < 0)
//             cmp = lower;
//         if (n < main[cmp])
//         {
//             if (middle - pair < 0)
//                 return (-1);
//             else 
//                 return (middle - pair);
//         }
//         return (middle);
//     }

//     comparison++;
//     if (n > main[middle])
//         return (binary_insert(group, main, n, middle + pair, upper, comparison));
//     else if (n < main[middle])
//         return (binary_insert(group, main, n, lower, middle - pair, comparison));
//     else
//         return (middle);
// }

// template <class T>
// void	PmergeMe::merge_main_pend(T &main, T pend, size_t group, int &comparison, T &a, T &b)
// {
//     size_t na = static_cast<size_t>(a[0]);
//     size_t nb = b[0];

//     size_t inserted = 1;
//     size_t ijs = 1;
//     int lowerbound = 0;
//     int upperbound = 0;
//     int pos;

//     while (inserted < nb)
//     {
//         for (size_t i = jsnum[ijs]; i > jsnum[ijs - 1]; --i)
//         {
//             if (i > nb)
//                 continue ;
//             lowerbound = group / 2 - 1;
//             if (i > na)
//                 upperbound = main.size() - 1;
//             else
//                 upperbound = a[i] - group / 2;
//             pos = binary_insert(group, main, pend[abs(b[i])], lowerbound, upperbound, comparison);
//             insert_and_update(group, main, pend, i, pos, a, b);
//             inserted++;
//         }
//         ijs++;
//     }
// }

// template <class T>
// void    PmergeMe::insert_and_update(size_t group, T &main, T &pend, int i, int pos, T &a, T &b)
// {
//     int pair = static_cast<int>(group) / 2;
//     int ib = abs(b[i]);

//     // std::cout << pos << std::endl;
//     // std::cout << ib << ", " << *(pend.begin() + ib - pair + 1) << ", " << *(pend.begin() + ib) << std::endl;
//     main.insert(main.begin() + pos + 1, pend.begin() + ib - pair + 1, pend.begin() + ib + 1);
//     // printc(main, "main");

//     b[i] = pos + pair;

//     for (int j = 1; j <= a[0]; ++j)
//     {
//         if (a[j] > pos)
//             a[j] += pair;
//     }

//     // printc(a, "a");
//     // printc(b, "b");
// }

// template <class T>
// void	PmergeMe::merge_main_nonparticipating(T &main, T nonParticipating)
// {
// 	main.insert(main.end(), nonParticipating.begin(), nonParticipating.end());
// }

// template <class T>
// T	PmergeMe::get_main(T &c, size_t group, size_t &a, size_t b)
// {
// 	T	main;
// 	for (size_t i = 0; i <= b; ++i)
// 		main.push_back(c[i]);
// 	for (; a < static_cast<size_t>(c.size()); a += group)
// 	{
// 		for (size_t i = a - group/2 + 1; i <= a; ++i)
// 			main.push_back(c[i]);
// 	}
// 	return (main);
// }

// template <class T>
// T	PmergeMe::get_pend(T &c, size_t group, size_t &b)
// {
// 	T	pend;
// 	for (b += group; b < static_cast<size_t>(c.size()); b += group)
// 	{
// 		for (size_t i = b - group/2 + 1; i <= b; ++i)
// 			pend.push_back(c[i]);
// 	}
// 	return (pend);
// }

// template <class T>
// T	PmergeMe::get_non_participating(T &c, size_t group, size_t a, size_t b)
// {
// 	T non_participating;
// 	size_t i;
// 	if (a > b)
// 		i = a - group + 1;
// 	else
// 		i = b - group + 1;

// 	if (i == c.size())
// 		return (non_participating);

// 	for (; i < c.size(); ++i)
// 		non_participating.push_back(c[i]);
	
// 	return (non_participating);
// }

// template <class T>
// T   PmergeMe::get_a_indexes(T &main, size_t group)
// {
//     T a;
    
//     size_t  pair = group / 2;
//     size_t  mainsize = main.size();
//     size_t  elements = mainsize / pair;

//     a.push_back(elements - 1);
//     for (size_t i = 2; i <= elements; ++i)
//         a.push_back((i * pair) - 1);
//     return (a);
// }

// template <class T>
// T   PmergeMe::get_b_indexes(T &pend, size_t group)
// {
//     T b;

//     size_t  pair = group / 2;
//     size_t  pendsize = pend.size();
//     size_t  elements = pendsize / pair;
    
//     b.push_back(elements + 1);
//     b.push_back(pair - 1);
//     for (size_t i = 1; i <= elements; ++i)
//         b.push_back(((i * pair) - 1) * -1);
//     return (b);
// }




