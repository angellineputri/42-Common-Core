#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator output = std::find(container.begin(), container.end(), value);
    if (output == container.end())
        throw std::runtime_error("Error: value not found inside the container!");
    else
        return (output);
}

#endif