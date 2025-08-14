#include <iostream>
#ifndef ITER_HPP
# define ITER_HPP

template <typename type, typename func_type>
void    iter(type *arr, int len, func_type f)
{
    if (!arr)
        throw std::runtime_error("Error: array passed is null");

    for (int i = 0; i < len; ++i)
    {
        try
        {
            f(arr[i]);
        }
        catch(const std::exception& e)
        {
            throw std::runtime_error("Error: failed to apply function");
        }
    }
}

#endif
