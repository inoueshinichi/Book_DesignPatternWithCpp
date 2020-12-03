#ifndef __FACTORY_METHOD_PRODUCT_HPP__
#define __FACTORY_METHOD_PRODUCT_HPP__

namespace Is
{
    class ProductInFactory
    {
    public:
        virtual ~ProductInFactory() {};
        virtual void use() = 0;
    };
}

#endif