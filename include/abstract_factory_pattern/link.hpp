#ifndef ABSTRACT_FACTORY_LINK_HPP
#define ABSTRACT_FACTORY_LINK_HPP

#include "item.hpp"

#include <string>

namespace Is
{
    using std::string;

    class Link : public Item
    {
    protected:
        string url_;

    public:
        Link(const string& caption, const string& url) : Item(caption), url_(url) {}
        virtual ~Link() {}
    };
}
#endif