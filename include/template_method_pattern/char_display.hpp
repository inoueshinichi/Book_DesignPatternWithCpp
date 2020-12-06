#ifndef TEMPLATE_METHOD_CHAR_DISPLAY_HPP
#define TEMPLATE_METHOD_CHAR_DISPLAY_HPP

#include "abstract_display.hpp"

namespace Is
{
    class CharDisplay : public AbstractDisplay
    {
        char ch_;
    
    public:
        CharDisplay(char ch) : ch_(ch) {}
        virtual ~CharDisplay() override {}
        virtual void open() override;
        virtual void print() override;
        virtual void close() override;
    };
}

#endif