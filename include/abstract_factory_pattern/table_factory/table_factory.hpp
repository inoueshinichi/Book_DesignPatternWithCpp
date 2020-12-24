#ifndef ABSTRACT_FACTORY_TABLE_FACTORY_HPP
#define ABSTRACT_FACTORY_TABLE_FACTORY_HPP

#include "table_link.hpp"
#include "table_tray.hpp"
#include "table_page.hpp"
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

    class TableFactory : public AbstractFactory
    {
    public:
        virtual shared_ptr<Link> createLink(const string& caption, const string& url) override
        {
            return std::static_pointer_cast<Link>(make_shared<TableLink>(caption, url));
        }

        virtual shared_ptr<Tray> createTray(const string& caption) override
        {
            return std::static_pointer_cast<Tray>(make_shared<TableTray>(caption));
        }

        virtual shared_ptr<Page> createPage(const string& title, const string& author) override
        {
            return std::static_pointer_cast<Page>(make_shared<TablePage>(title, author));
        }
    };
}
#endif