#ifndef __BUILDER_HPP__
#define __BUILDER_HPP__
#include <string>
#include <vector>

namespace Is
{
    using std::string;
    using std::vector;

    class Builder
    {
    public:
        virtual void makeTitle(const string& title) = 0;
        virtual void makeString(const string& str) = 0;
        virtual void makeItems(const vector<string>& items) = 0;
        virtual void close() = 0;
    };
}

#endif