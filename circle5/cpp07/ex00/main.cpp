#include "whatever.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

int main()
{
    int a = 2;
    int b = 3;
    std::cout << BLUE << "[1] Test swap function for int" << RESET << std::endl;
    std::cout << MAGENTA << "before: " << RESET << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << MAGENTA << "after : " << RESET << "a = " << a << ", b = " << b << std::endl << std::endl;

    std::cout << BLUE << "[2] Test min and max function for int" << RESET << std::endl;
    std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
    std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;


    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << BLUE << "[3] Test swap function for str" << RESET << std::endl;
    std::cout << MAGENTA << "before: " << RESET << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << MAGENTA << "after : " << RESET << "c = " << c << ", d = " << d << std::endl << std::endl;
    std::cout << BLUE << "[4] Test min and max function for str" << RESET << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    // ::swap(a, c);
    return (0);
}
