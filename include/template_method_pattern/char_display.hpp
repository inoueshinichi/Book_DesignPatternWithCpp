#ifndef TEMPLATE_METHOD_CHAR_DISPLAY_HPP
#define TEMPLATE_METHOD_CHAR_DISPLAY_HPP

#include "../common.hpp"

#include "abstract_display.hpp"

namespace Is
{
    class DP_API CharDisplay : public AbstractDisplay
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