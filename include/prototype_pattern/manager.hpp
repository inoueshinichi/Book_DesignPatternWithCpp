#ifndef PROTOTYPE_MANAGER_HPP
#define PROTOTYPE_MANAGER_HPP

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
        static showcase& registry();  
        static void register_(const string& name, shared_ptr<Product> proto);
        static shared_ptr<Product> create(const string& proto_name);
    };
}
#endif
