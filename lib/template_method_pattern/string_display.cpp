#include "template_method_pattern/string_display.hpp"

#include <iostream>

namespace Is
{
    void StringDisplay::printLine()
    {
        std::cout << "+";
        for (int i = 0; i < width_; ++i)
        {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;
    }

    void StringDisplay::open()
    {
        printLine();
    }

    void StringDisplay::print()
    {
        std::cout << "|" << str_ << "|" << std::endl;
    }

    void StringDisplay::close()
    {
        printLine();
    }
}