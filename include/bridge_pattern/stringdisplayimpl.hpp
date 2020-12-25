#ifndef BRIDGE_STRINGDISPLAY_IMPL_HPP
#define BRIDGE_STRINGDISPLAY_IMPL_HPP

#include "displayimpl.hpp"

#include <cstdio>
#include <sstream>
#include <string>
#include <memory>

namespace Is
{
    using std::string;
    using std::stringstream;

    class StringDisplayImpl : public DisplayImpl
    {
        string str_;
        int width_;

        void printLine()
        {
            stringstream ss;
            ss << "+";
            for (int i = 0; i < width_; ++i)
            {
                ss << "-";
            }
            ss << "+";

            std::printf("%s\n", ss.str().c_str());
        }

    public:
        StringDisplayImpl(const string& str) : str_(str)
        {
            // 日本語のマルチバイト文字が入ると以下のルールは成立しない.
            // おとなしくUTF-8用のライブラリを導入すべし
            width_ = str_.length();
        }

        void rawOpen()
        {
            printLine();
        }

        void rawPrint()
        {
            std::printf("| %s |\n", str_.c_str());
        }

        void rawClose()
        {
            printLine();
        }
    };
}
#endif