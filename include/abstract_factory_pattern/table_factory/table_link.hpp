#ifndef ABSTRACT_FACTORY_TABLE_LINK_HPP
#define ABSTRACT_FACTORY_TABLE_LINK_HPP

#include "../../common.hpp"
#include "../link.hpp"

#include <sstream>

namespace Is
{
    using std::stringstream;

    class DP_API TableLink : public Link
    {
    public:
        TableLink(const string& caption, const string& url) : Link(caption, url) {}
        virtual ~TableLink() {}

        virtual string makeHTML() override
        {
            stringstream ss;
            ss << "<td><a href=\"";
            ss << url_;
            ss << "\">";
            ss << caption_;
            ss << "</a></td>\n";
            return ss.str();
        }
    };
}

#endif