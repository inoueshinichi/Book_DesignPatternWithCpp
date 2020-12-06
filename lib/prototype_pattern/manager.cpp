#include "prototype_pattern/manager.hpp"


namespace Is
{
    Manager::showcase& Manager::registry()
    {
        static showcase a;
        return a;
    }   

    void Manager::register_(const string& name, shared_ptr<Product> proto)
    {
        showcase& a = registry();
        a.emplace(name, proto);
    }

    shared_ptr<Product> Manager::create(const string& proto_name)
    {
        showcase& a = registry();
        auto proto = a[proto_name]->createClone();
        return proto;
    }
}