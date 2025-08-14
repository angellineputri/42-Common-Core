#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void)
{
    int i = std::rand() % 3;
    Base *p;

    std::cout << "Address \'";
    switch (i)
    {
        case 0:
            p = new A();
            std::cout << MAGENTA << p << RESET << "\':" << MAGENTA << " Generating object A" << RESET << std::endl;
            return (p);
        case 1:
            p = new B();
            std::cout << MAGENTA << p << RESET << "\':" << MAGENTA << " Generating object B" << RESET << std::endl;
            return (p);
        default:
            p = new C();
            std::cout << MAGENTA << p << RESET << "\'" << MAGENTA << " Generating object C" << RESET << std::endl;
            return (p);
    }
}
