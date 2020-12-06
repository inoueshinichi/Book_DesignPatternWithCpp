#ifndef TEMPLATE_METHOD_STRING_DISPLAY_HPP
#define TEMPLATE_METHOD_STRING_DISPLAY_HPP

#include "abstract_display.hpp"

#include <string>

namespace Is
{
    using std::string;

    class StringDisplay : public AbstractDisplay
    {
        string str_;
        int width_;

        void printLine();

    public:
        StringDisplay(const string& str)
            : str_(str), width_(str.length())
        {}

        virtual void open() override;
        virtual void print() override;
        virtual void close() override;

    };
}
#endif
