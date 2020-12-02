#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <memory>
#include <string>

namespace Is
{
    using std::shared_ptr;
    using std::string;

    class Product;

    class Factory
    {
    public:
        shared_ptr<Product> create(const string& owner);

    protected:
        virtual shared_ptr<Product>&& createProduct(const string& owner) = 0;
        virtual void registerProduct(shared_ptr<Product> product) = 0;
    };
}

#endif