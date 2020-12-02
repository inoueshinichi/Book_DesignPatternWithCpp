#include "factory_method_pattern/factory.hpp"
#include "factory_method_pattern/product.hpp"


namespace Is
{
    /**
     * @brief 
     * 
     * @param owner 
     * @return shared_ptr<Product> 
     */
    shared_ptr<Product> Factory::create(const string& owner)
    {
        shared_ptr<Product> p = static_cast<shared_ptr<Product>>(this->createProduct(owner));
        this->registerProduct(p);
        return p;
    }
}