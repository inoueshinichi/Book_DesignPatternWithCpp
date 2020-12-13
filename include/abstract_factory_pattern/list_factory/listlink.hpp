#ifndef ABSTRACT_FACTORY_LIST_LINK_HPP
#define ABSTRACT_FACTORY_LIST_LINK_HPP

#include "../link.hpp"

#include <sstream>

namespace Is
{
    class ListLink : public Link
    {
    public:
        ListLink(const string& caption, const string& url) : Link(caption, url) {}
        virtual ~ListLink() {}

        virtual string makeHTML() override
        {
            std::stringstream ss;
            ss << " <li><a href=\"" << url_ << "\">" << caption_ << "</a></li>" << std::endl;
            return ss.str();
        } 
    };
}
#endif