#ifndef ADAPTER_PRINT_BANNER_HPP
#define ADAPTER_PRINT_BANNER_HPP

#include "../common.hpp"
#include "print.hpp"
#include "banner.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API PrintBanner : public Print
    {
        Banner banner_;

    public:
        PrintBanner(const string& str) : banner_(str) {}
        void printWeak() override { banner_.showWithParen(); }
        void printStrong() override { banner_.showWithAster(); }
    };
}
#endif