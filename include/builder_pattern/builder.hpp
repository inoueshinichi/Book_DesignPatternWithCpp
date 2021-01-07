#ifndef BUILDER_BUILDER_HPP
#define BUILDER_BUILDER_HPP

#include "../common.hpp"

#include <string>
#include <vector>

namespace Is
{
    using std::string;
    using std::vector;

    class DP_API Builder
    {
    public:
        virtual ~Builder() {}
        virtual void makeTitle(const string& title) = 0;
        virtual void makeString(const string& str) = 0;
        virtual void makeItems(const vector<string>& items) = 0;
        virtual void close() = 0;
    };
}
#endif
