#include "prototype_pattern/manager.hpp"


namespace Is
{
    /**
     * @brief 
     * 
     * @return showcase& 
     */
    Manager::showcase& Manager::registry()
    {
        static showcase a;
        return a;
    }   

    /**
     * @brief 
     * 
     * @param name 
     * @param proto 
     */
    void Manager::register_(const string& name, shared_ptr<Product> proto)
    {
        showcase& a = registry();
        a.emplace(name, proto);
    }

    /**
     * @brief 
     * 
     * @param proto_name 
     * @return shared_ptr<Product> 
     */
    shared_ptr<Product> Manager::create(const string& proto_name)
    {
        showcase& a = registry();
        auto proto = a[proto_name]->createClone();
        return proto;
    }
}