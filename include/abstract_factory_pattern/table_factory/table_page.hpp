#ifndef ABSTRACT_FACTORY_TABLE_PAGE_HPP
#define ABSTRACT_FACTORY_TABLE_PAGE_HPP

#include "../page.hpp"

#include <string>
#include <sstream>

namespace Is
{
    using std::string;
    using std::stringstream;

    class TablePage : public Page
    {
    public:
        TablePage(const string& title, const string& author) : Page(title, author) {}
        virtual ~TablePage() {}

        virtual string makeHTML() override
        {
            stringstream ss;
            ss << "<html><head><title>" << title_ << "</title></head>\n";
            ss << "<body>\n";
            ss << "<h1>" << title_ << "</h1>\n";
            ss << "<table width=\"80\" border=\"3\">\n";
            auto iter = content_.begin();
            while (iter != content_.end())
            {
                ss << "<tr>" << (*iter)->makeHTML() << "</tr>";
                ++iter;
            }
            ss << "</table>\n";
            ss << "<hr><address>" + author_ << "</address>";
            ss << "</body></html>\n";
            return ss.str();
        }
    };
}
#endif