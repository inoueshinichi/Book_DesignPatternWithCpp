#ifndef ABSTRACT_FACTORY_LINK_HPP
#define ABSTRACT_FACTORY_LINK_HPP

#include "../common.hpp"
#include "item.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API Link : public Item
    {
    protected:
        string url_;

    public:
        Link(const string& caption, const string& url) : Item(caption), url_(url) {}
        virtual ~Link() {}
    };
}
#endif