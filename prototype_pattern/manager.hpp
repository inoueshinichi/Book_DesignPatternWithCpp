#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include "product.hpp"

#include <map>
#include <unordered_map>
#include <memory>
#include <string>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::unordered_map;
    using std::string;

    class Manager
    {
        using showcase = unordered_map<string, shared_ptr<Product>>;

    public:
        static showcase& registry()
        {
            static showcase a;
            return a;
        }   

        static void register_(const string& name, shared_ptr<Product> proto)
        {
            showcase& a = registry();
            a.emplace(name, proto);
        }

        static shared_ptr<Product> create(const string& proto_name)
        {
            showcase& a = registry();
            auto proto = a[proto_name]->createClone();
            return proto;
        }
    };
}


#endif