#ifndef DECORATOR_DECOBASEDISPLAY_HPP
#define DECORATOR_DECOBASEDISPLAY_HPP

#include "../common.hpp"

#include <iostream>
#include <string>

namespace Is
{
    using std::string;

    class DP_API DecoBaseDisplay
    {
    public:
        DecoBaseDisplay() {}
        virtual ~DecoBaseDisplay() {}

        virtual int getColumns() = 0;
        virtual int getRows() = 0;
        virtual string getRowText(int row) = 0;

        void show()
        {
            for (int i = 0; i < getRows(); ++i)
            {
                std::cout << getRowText(i) << std::endl;
            }
        }
    };
}
#endif