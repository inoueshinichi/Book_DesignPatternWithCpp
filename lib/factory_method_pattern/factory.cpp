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
    shared_ptr<ProductInFactory> Factory::create(const string& owner)
    {
        shared_ptr<ProductInFactory> p = this->createProduct(owner);
        this->registerProduct(p);
        return p;
    }
}