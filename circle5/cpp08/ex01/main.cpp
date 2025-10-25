#include "Span.hpp"
#include <math.h>
#include <array>

void    test_construction()
{
    std::cout << BLUE << "[1] Testing vector construction" << RESET << std::endl;
    Span    span1 = Span();
    Span    span3 = Span(100000);
    Span    span2 = Span(-1);
    std::cout << std::endl;
}

void    test_exceptions()
{
    std::cout << BLUE << std::endl << "[2] Testing exceptions" << RESET << std::endl;
    std::cout << YELLOW << "* add number to a span of max_capacity 0" << RESET << std::endl;
    Span    span_zero = Span();
    try
    {
        span_zero.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    int shortest;
    int longest;
    std::cout << YELLOW << std::endl << "* calling shortest and longest span function without any numbers inside the span" << RESET << std::endl;
    try
    {
        shortest = span_zero.shortestSpan();
        std::cout << "shortest span is: " << shortest << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "shortest span is: " << RED << e.what() << RESET << std::endl;
    }

    try
    {
        longest = span_zero.longestSpan();
        std::cout << "longest span is: " << longest << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "longest span is: " << RED << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << std::endl << "* calling shortest and longest span function with just 1 number inside the span" << RESET << std::endl;
    Span    span_one = Span(3);
    span_one.addNumber(1);
    std::cout << YELLOW << "span: " << RESET; span_one.print(1); std::cout << std::endl;
    try
    {
        shortest = span_one.shortestSpan();
        std::cout << "shortest span is: " << shortest << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "shortest span is: " << RED << e.what() << RESET << std::endl;
    }

    try
    {
        longest = span_one.longestSpan();
        std::cout << "longest span is: " << longest << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "longest span is: " << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
}

void    test_span_functions()
{
    std::cout << BLUE << std::endl << "[3] Testing addNumber()" << RESET << std::endl;
    Span    span = Span(3);
    std::array<int, 4>  arr = {-5, -5, 10202, 1};

    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        try
        {
            span.addNumber(arr[i]);
            std::cout << "Successfully inserted \'" << MAGENTA << arr[i] << RESET << "\' to span" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Attempting to insert \'" << MAGENTA << arr[i] << RESET << "\' to span: " << RED << e.what() << RESET << std::endl;
        }
    }

    std::cout << BLUE << std::endl << "[4] Testing shortestSpan()" << RESET << std::endl;
    std::cout << YELLOW << "span: " << RESET; span.print(0); std::cout << std::endl;
    try
    {
        std::cout << YELLOW << "shortest span: " << RESET << span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << BLUE << std::endl << "[5] Testing longestSpan()" << RESET << std::endl;
    std::cout << YELLOW << "span: " << RESET; span.print(0); std::cout << std::endl;
    try
    {
        std::cout << YELLOW << "longest span: " << RESET << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

void    test_with_addRange()
{
    std::cout << BLUE << std::endl << "[6] Testing addRange()" << RESET << std::endl;
    std::vector<int>    v;
    for (int i = 0; i < 12002; ++i)
        v.push_back(i);

    std::deque<int>    dq;
    for (int i = 0; i < 12000; ++i)
        dq.push_back(i);

    Span    span = Span(12000);
    std::cout << "Adding range of data from a larger vector: ";
    try
    {
        span.addRange(v.begin(), v.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << "Adding range of data from deque: ";
    try
    {
        span.addRange(dq.begin(), dq.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    std::cout << YELLOW << "span: " << RESET; span.print(0); std::cout << std::endl;
    try
    {
        std::cout << YELLOW << "shortest span: " << RESET << span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }    
    try
    {
        std::cout << YELLOW << "longest span: " << RESET << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
}

void    test_from_pdf()
{
    std::cout << BLUE << std::endl << "[7] Subject PDF tests" << RESET << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main()
{
    test_construction();
    test_exceptions();
    test_span_functions();
    test_with_addRange();
    test_from_pdf();
    return (0);
}
