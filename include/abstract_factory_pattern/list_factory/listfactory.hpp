#ifndef ABSTRACT_FACTORY_LIST_FACTORY_HPP
#define ABSTRACT_FACTORY_LIST_FACTORY_HPP

#include "listlink.hpp"
#include "listtray.hpp"
#include "listpage.hpp"
#include "../abstract_factory.hpp"
#include "../link.hpp"
#include "../tray.hpp"
#include "../page.hpp"

#include <string>
#include <memory>

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::make_shared;

    class ListFactory : public AbstractFactory
    {
    public:
        virtual shared_ptr<Link> createLink(const string& caption, const string& url) override
        {
            return std::static_pointer_cast<Link>(make_shared<ListLink>(caption, url));
        }

        virtual shared_ptr<Tray> createTray(const string& caption)
        {
            return std::static_pointer_cast<Tray>(make_shared<ListTray>(caption));
        }

        virtual shared_ptr<Page> createPage(const string& title, const string& author)
        {
            return std::static_pointer_cast<Page>(make_shared<ListPage>(title, author));
        }
    };
}
#endif