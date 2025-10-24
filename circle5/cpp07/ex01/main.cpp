#include "iter.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

template <typename type>
void    print_arr(type *arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (i != len - 1)
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i] << std::endl;
    }
}

void    print_int_element(const int &num)
{
    std::cout << num;
}

void    add_one(int &num)
{
    num++;
}

void    bad_function_int(int &num)
{
    if (num == 3)
        throw std::runtime_error("Error: bad function failed for the number 3!");
    add_one(num);
}

void    print_str_element(const std::string &str)
{
    std::cout << str;
}

void    delete_vocal(std::string &str)
{
    if (str.empty())
        throw std::runtime_error("Error: string is null!");
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'e' || str[i] == 'o')
            str[i] = ' ';
    }
}

void    bad_function_str(std::string &str)
{
    if (str == "two")
        throw std::runtime_error("Error: bad function failed for the string \"two\"!");
    delete_vocal(str);
}

void    test_iter_on_int_arr()
{
    int int_arr[5] = {0, 1, 2, 3, 4};
    int *invalid_int_arr = NULL;

    std::cout << BLUE << "[1] Test iter function on int array" << RESET << std::endl;
    std::cout << MAGENTA << "/// testing function with valid non-const array, valid length, and valid function ('add_one') ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(int_arr, 5);
    try
    {
        ::iter(int_arr, 5, add_one);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "This test was not supposed to fail.." << std::endl << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(int_arr, 5); std::cout << std::endl;

    std::cout << MAGENTA << "/// testing function with valid const array, valid length, and valid function ('print_int_element') ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(int_arr, 5);
    try
    {
        ::iter(static_cast<const int *>(int_arr), 5, print_int_element);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "This test was not supposed to fail.." << std::endl << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(int_arr, 5); std::cout << std::endl;

    std::cout << MAGENTA << "/// testing function with invalid array, valid length, and valid function ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(int_arr, 5);
    try
    {
        ::iter(invalid_int_arr, 5, add_one);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(int_arr, 5); std::cout << std::endl;

    std::cout << MAGENTA << "/// testing function with valid non-const array, valid length, and bad function ('bad_function_int') ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(int_arr, 5);
    try
    {
        ::iter(int_arr, 5, bad_function_int);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(int_arr, 5); std::cout << std::endl;
}

void    test_iter_on_str_arr()
{
    std::string str_arr[3] = {"one", "two", "three"};
    std::string *invalid_str_arr = NULL;
    std::cout << BLUE << "[2] Test iter function on str array" << RESET << std::endl;
    std::cout << MAGENTA << "/// testing function with valid non-const array, valid length, and valid function ('delete_vocal') ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(str_arr, 3);
    try
    {
        ::iter(str_arr, 3, delete_vocal);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "This test was not supposed to fail.." << std::endl << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(str_arr, 3); std::cout << std::endl;

    std::cout << MAGENTA << "/// testing function with valid const array, valid length, and valid function ('print_str_element') ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(str_arr, 3);
    try
    {
        ::iter(static_cast<const std::string *>(str_arr), 3, print_str_element);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "This test was not supposed to fail.." << std::endl << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(str_arr, 3); std::cout << std::endl;

    std::cout << MAGENTA << "/// testing function with invalid array, valid length, and valid function ('delete_vocal') ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(str_arr, 3);
    try
    {
        ::iter(invalid_str_arr, 3, delete_vocal);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(str_arr, 3); std::cout << std::endl;

    str_arr[0] = "one";
    str_arr[1] = "two";
    str_arr[2] = "three";
    std::cout << MAGENTA << "/// testing function with valid non-const array, valid length, and bad function ('bad_function_str') ///" << RESET << std::endl;
    std::cout << YELLOW << "before: " << RESET; print_arr(str_arr, 3);
    try
    {
        ::iter(str_arr, 3, bad_function_str);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "after : " << RESET; print_arr(str_arr, 3); std::cout << std::endl;
}

int main()
{
    test_iter_on_int_arr();
    test_iter_on_str_arr();
    return (0);
}
