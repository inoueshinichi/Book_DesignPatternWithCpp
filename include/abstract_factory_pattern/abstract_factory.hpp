#ifndef ABSTRACT_FACTORY_FACTORY_HPP
#define ABSTRACT_FACTORY_FACTORY_HPP

#include "item.hpp"
#include "link.hpp"
#include "tray.hpp"
#include "page.hpp"

#include <string>
#include <unordered_map>
#include <memory>
#include <typeinfo>
#include <cxxabi.h> // typeid().name()の戻り値をデマングルするためにつかう.


namespace Is
{
    using std::unordered_map;
    using std::shared_ptr;

    class AbstractFactory
    {
        using Registry_t = unordered_map<string, shared_ptr<AbstractFactory>>;

        static Registry_t& getRegistry()
        {
            static Registry_t registry_;
            return registry_;
        }

    public:
        static shared_ptr<AbstractFactory> getFactory(const string& classname);

        template <typename FACTORY>
        static void addFactory()
        {
            Registry_t& registry = getRegistry();   

            /* マングリングされたtypeid().name()の戻り値をデマングルしてクラス名を取得する */
            string factory_name;
            const std::type_info& id = typeid(FACTORY); // RTTI(Run Time Type Identifier)
            int stat;
            char* name = abi::__cxa_demangle(id.name(), 0, 0, &stat);
            if (name != nullptr)
            {
                if (stat == 0) // stats == 0で成功
                {
                    factory_name = name;
                    ::free(name);
                }
            }

            auto iter = registry.find(factory_name);
            if (iter == registry.end())
            {
                auto factory = std::static_pointer_cast<AbstractFactory>(std::make_shared<FACTORY>());
                registry.insert({factory_name, factory});
            }
        }


        virtual shared_ptr<Link> createLink(const string& caption, const string& url) = 0;
        virtual shared_ptr<Tray> createTray(const string& caption) = 0;
        virtual shared_ptr<Page> createPage(const string& title, const string& author) = 0;
    };
}
#endif