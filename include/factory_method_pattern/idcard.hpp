#ifndef __FACTORY_METHOD_IDCARD_HPP__
#define __FACTORY_METHOD_IDCARD_HPP__

#include "factory_method_pattern/product.hpp"

#include <memory>
#include <string>

namespace Is
{
    using std::shared_ptr;
    using std::string;

    class IdCard : public ProductInFactory
    {
        string owner_;

    public:
        IdCard(const string& owner);
        void use() override;
        string& getOwner() { return owner_; }
    };
}

#endif