#ifndef FACTORY_METHOD_IDCARD_HPP
#define FACTORY_METHOD_IDCARD_HPP

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
