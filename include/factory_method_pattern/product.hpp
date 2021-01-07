#ifndef FACTORY_METHOD_PRODUCT_HPP
#define FACTORY_METHOD_PRODUCT_HPP

#include "../common.hpp"

namespace Is
{
    class DP_API ProductInFactory
    {
    public:
        virtual ~ProductInFactory() {}
        virtual void use() = 0;
    };
}
#endif
