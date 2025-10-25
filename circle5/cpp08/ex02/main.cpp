#include <iostream>
#include <stack>
#include "MutantStack.hpp"

void    test_constructors()
{
    std::cout << BLUE << std::endl << "[1] Test mstack default constructors" << RESET << std::endl;
    MutantStack<int>    mstack;
    mstack.push(6);
    mstack.push(2);
    std::cout << YELLOW << "* pushed '6' and '2' to mstack *" << RESET << std::endl;
    std::cout << "the size of mstack: " << MAGENTA << mstack.size() << RESET << std::endl;

    std::cout << BLUE << std::endl << "[2] Test mstack copy constructors" << RESET << std::endl;
    MutantStack<int>    mstack_copy_const(mstack);
    std::cout << "the size of mstack copy constructor: " << MAGENTA << mstack_copy_const.size() << RESET << std::endl;

    std::cout << BLUE << std::endl << "[3] Test original stack copy construct with mstack as the parameter" << RESET << std::endl;
    std::stack<int> st(mstack);
    std::cout << "the size of stack: " << MAGENTA << mstack.size() << RESET << std::endl;
    std::cout << "top of the stack: " << MAGENTA << st.top() << RESET << std::endl << std::endl;
}

void    test_mstack_regular_functions()
{    
    std::cout << BLUE << std::endl << "[4] Testing mstack.push()" << RESET << std::endl;
    MutantStack<int>    mstack;
    for (unsigned int i = 1; i <= 10; ++i)
    {
        try
        {
            mstack.push(i);
            std::cout << "succesfully pushed \'" << MAGENTA << i << RESET << "\' to mstack" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << BLUE << std::endl << "[5] Testing mstack.empty()" << RESET << std::endl;
    if (mstack.empty())
        std::cout << "mstack is empty" << std::endl;
    else
        std::cout << "mstack is not empty" << std::endl;

    std::cout << BLUE << std::endl << "[6] Testing mstack.size()" << RESET << std::endl;
    std::cout << "the size of mstack: " << MAGENTA << mstack.size() << RESET << std::endl;

    std::cout << BLUE << std::endl << "[7] Testing mstack.top() and mstack.pop()" << RESET << std::endl;
    std::cout << "top of the stack: " << MAGENTA << mstack.top() << RESET << std::endl;
    std::cout << "popped the value of \'" << MAGENTA << mstack.top() << RESET << "\' from mstack" << std::endl;
    mstack.pop();
    std::cout << "top of the stack: " << MAGENTA << mstack.top() << RESET << std::endl;
}

void    test_mstack_iterator()
{
    std::cout << BLUE << std::endl << "[8] Testing mstack iterator" << RESET << std::endl;
    MutantStack<int> mstack;
    for (unsigned int i = 1; i <= 10; ++i)
    {
        try
        {
            mstack.push(i);
            std::cout << "succesfully pushed \'" << MAGENTA << i << RESET << "\' to mstack" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << YELLOW << "printing values inside stack using iterator: " << RESET << *it << std::endl;
    }

    std::cout << BLUE << std::endl << "[9] Test finding the value \'" << RESET << "6" << BLUE << "\' inside mstack" << RESET << std::endl;
    MutantStack<int>::iterator it = std::find(mstack.begin(), mstack.end(), 6);
    if (it != mstack.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found" << std::endl;

    std::cout << BLUE << std::endl << "[10] Test finding the value \'" << RESET << "20" << BLUE << "\' inside mstack" << RESET << std::endl;
    it = std::find(mstack.begin(), mstack.end(), 20);
    if (it != mstack.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found" << std::endl;

}

void    test_from_subject_pdf()
{
    std::cout << BLUE << std::endl << "[11] Tests from subject PDF" << RESET << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
}

int main()
{
    test_constructors();
    test_mstack_regular_functions();
    test_mstack_iterator();
    test_from_subject_pdf();
}
