#ifndef FACTORY_METHOD_FACTORY_HPP
#define FACTORY_METHOD_FACTORY_HPP

#include <memory>
#include <string>

namespace Is
{
    using std::shared_ptr;
    using std::string;

    class ProductInFactory;

    class Factory
    {
    public:
        virtual ~Factory() {}
        shared_ptr<ProductInFactory> create(const string& owner);

    protected:
        virtual shared_ptr<ProductInFactory> createProduct(const string& owner) = 0;
        virtual void registerProduct(shared_ptr<ProductInFactory> product) = 0;

    };
}
#endif
