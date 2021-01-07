#ifndef BRIDGE_STRINGDISPLAY_IMPL_HPP
#define BRIDGE_STRINGDISPLAY_IMPL_HPP

#include "utf8.h"

#include "../common.hpp"
#include "displayimpl.hpp"

#include <cstdio>
#include <sstream>
#include <string>
#include <memory>

namespace Is
{
    using std::string;
    using std::stringstream;

    class DP_API StringDisplayImpl : public DisplayImpl
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
            auto width = utf8::distance(str.begin(), str.end());
            std::cout << "width: " << width << std::endl;
            // width_ = width;
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