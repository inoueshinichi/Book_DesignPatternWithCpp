#include "template_method_pattern/char_display.hpp"

#include <iostream>

namespace Is
{
    void CharDisplay::open()
    {
        std::cout << "<<";
    }

    void CharDisplay::print()
    {
        std::cout << ch_;
    }

    void CharDisplay::close()
    {
        std::cout << "<<" << std::endl;
    }
}