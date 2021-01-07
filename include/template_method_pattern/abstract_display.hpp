#ifndef TEMPLATE_METHOD_ABSTRACT_DISPLAY_HPP
#define TEMPLATE_METHOD_ABSTRACT_DISPLAY_HPP

#include "../common.hpp"

namespace Is
{
    class DP_API AbstractDisplay
    {
    public:
        AbstractDisplay() {}
        virtual ~AbstractDisplay() {}
        virtual void open() = 0;
        virtual void print() = 0;
        virtual void close() = 0;
        void display()
        {
            this->open();
            for (int i = 0; i < 5; ++i)
            {
                this->print();
            }
            this->close();
        }
    };
}

#endif