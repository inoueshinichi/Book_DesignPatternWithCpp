#include "factory_method_pattern/idcard_factory.hpp"

#include "factory_method_pattern/product.hpp"

namespace Is
{
    shared_ptr<ProductInFactory> IdCardFactory::createProduct(const string& owner)
    {
        return std::static_pointer_cast<ProductInFactory>(std::make_shared<IdCard>(owner));
    }

    void IdCardFactory::registerProduct(shared_ptr<ProductInFactory> product)
    {
       auto idcard = std::dynamic_pointer_cast<IdCard>(product);
       owners_.push_back(idcard);
    }

     vector<shared_ptr<IdCard>>& IdCardFactory::getOwners()
     {
         return owners_;
     }
}
