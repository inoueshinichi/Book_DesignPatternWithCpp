#ifndef ABSTRACT_FACTORY_LIST_PAGE_HPP
#define ABSTRACT_FACTORY_LIST_PAGE_HPP

#include "../page.hpp"

#include <string>
#include <sstream>
#include <memory>

namespace Is
{
    using std::string;
    using std::shared_ptr;

    class ListPage : public Page
    {
    public:
        ListPage(const string& title, const string& author) : Page(title, author) {}
        virtual ~ListPage() {}

        virtual string makeHTML() override
        {
            std::stringstream ss;
            ss << "<html><head><title>" << title_ << "</title></head>" << std::endl;
            ss << "<body>" << std::endl;
            ss << "<h1>" << title_ << "</h1>" << std::endl;
            ss << "<ul>" << std::endl;

            auto iter = content_.begin();
            for (; iter != content_.end(); ++iter)
            {
                ss << (*iter)->makeHTML();
            }
            ss << "</ul>" << std::endl;
            ss << "<hr><address>" << author_ << "</address>";
            ss << "</body></html>" << std::endl;

            return ss.str();
        }
    };
}
#endif