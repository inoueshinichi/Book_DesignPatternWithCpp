#ifndef ADAPTER_PRINT_HPP
#define ADAPTER_PRINT_HPP

#include <iostream>

namespace Is
{
    class Print
    {
    public:
        virtual void printWeak() = 0; // { std::cout << "Print's printWeak()" << std::endl; };
        virtual void printStrong() = 0; //{ std::cout << "Print's printStrong()" << std::endl; };
    };
}
#endif