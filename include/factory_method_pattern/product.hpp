#ifndef FACTORY_METHOD_PRODUCT_HPP
#define FACTORY_METHOD_PRODUCT_HPP

namespace Is
{
    class ProductInFactory
    {
    public:
        virtual ~ProductInFactory() {}
        virtual void use() = 0;
    };
}
#endif
