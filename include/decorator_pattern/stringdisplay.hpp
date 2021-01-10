#ifndef DECORATOR_STRINGDISPLAY_HPP
#define DECORATOR_STRINGDISPLAY_HPP

#include "../common.hpp"
#include "display.hpp"

#include <string>

namespace Is
{
    class DP_API DecoStringDisplay : public DecoBaseDisplay
    {
        string str_;

    public:
        DecoStringDisplay(const string& str) : str_(str) {}
        virtual ~DecoStringDisplay() {}

        virtual int getColumns() override
        {
            return str_.length(); // utf8なので日本語だと文字列数が合わない
        } 

        virtual int getRows() override
        {
            return 1;
        }

        virtual string getRowText(int row) override
        {
            if (row == 0)
            {
                return str_;
            }
            else
            {
                using namespace std::literals::string_literals;
                return ""s;
            }
        }
    };
}
#endif