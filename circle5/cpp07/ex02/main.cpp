#include "Array.hpp"

template <typename type>
void    print_arr(const Array<type> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i != arr.size() - 1)
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i] << std::endl;
    }
}

void    test_constructors()
{
    std::cout << BLUE << "[1] Test default constructor" << RESET << std::endl;
    std::cout << MAGENTA << "/// integer array ///" << std::endl;
    Array<int>  int_arr_heap;

    std::cout << MAGENTA << "/// string array ///" << std::endl;
    Array<std::string>  str_arr_heap;

    std::cout << BLUE << "[2] Test constructor with parameter" << RESET << std::endl;
    std::cout << MAGENTA << "/// integer array ///" << std::endl;
    Array<int>  *int_arr_stack = new Array<int>(5);
    (*int_arr_stack)[0] = 1;
    (*int_arr_stack)[1] = 2;

    std::cout << MAGENTA << "/// string array ///" << std::endl;
    Array<std::string>  *str_arr_stack = new Array<std::string>(5);
    (*str_arr_stack)[0] = "original";
    (*str_arr_stack)[1] = "original";

    std::cout << BLUE << "[3] Test copy constructor" << RESET << std::endl;
    std::cout << MAGENTA << "/// integer array before changes ///" << std::endl;
    Array<int>  int_arr_copy(*int_arr_stack);
    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy constructor: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_copy);
    std::cout << std::endl;

    std::cout << MAGENTA << "/// integer array after changes ///" << std::endl;
    (*int_arr_stack)[1] = 50;
    (*int_arr_copy)[1] = 100;

    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy constructor: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_copy);
    std::cout << std::endl;

    std::cout << MAGENTA << "/// string array before changes ///" << std::endl;
    Array<std::string>  str_arr_copy(str_arr_stack);
    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy constructor: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_copy);
    std::cout << std::endl;

    std::cout << MAGENTA << "/// string array after changes ///" << std::endl;
    (*str_arr_copy)[1] = "copy constructor";
    (*str_arr_stack)[1] = "new original";

    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy constructor: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_copy);
    std::cout << std::endl;

    //reset
    (*int_arr_stack)[1] = 2;
    (*str_arr_stack)[1] = "original";

    std::cout << BLUE << "[4] Test copy assignment" << RESET << std::endl;
    int_arr_copy = int_arr_stack;
    str_arr_copy = str_arr_stack;

    std::cout << MAGENTA << "/// integer array before changes ///" << std::endl;
    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy assignment: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_copy);
    std::cout << std::endl;

    std::cout << MAGENTA << "/// integer array after changes ///" << std::endl;
    (*int_arr_stack)[1] = 50;
    (*int_arr_copy)[1] = 100;

    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy constructor: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &int_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(int_arr_copy);
    std::cout << std::endl;

    std::cout << MAGENTA << "/// string array before changes ///" << std::endl;
    Array<std::string>  str_arr_copy(str_arr_stack);
    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy constructor: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_copy);
    std::cout << std::endl;

    std::cout << MAGENTA << "/// string array after changes ///" << std::endl;
    (*str_arr_stack)[1] = "copy constructor";
    (*str_arr_copy)[1] = "new original";

    std::cout << YELLOW << "original: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_stack << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_stack);
    std::cout << std::endl;

    std::cout << YELLOW << "copy constructor: " << RESET << std::endl;
    std::cout << YELLOW << "address = " << &str_arr_copy << std::endl;
    std::cout << YELLOW << "array = " << RESET;
    print_arr(str_arr_copy);
    std::cout << std::endl;

    std::cout << BLUE << "[5] Destructor" << RESET << std::endl;
    delete int_arr_stack;
    delete str_arr_stack;
}

void    test_operators_and_function()
{

}

int main()
{
    test_constructors();
    test_operators_and_function();
    return (0);
}
