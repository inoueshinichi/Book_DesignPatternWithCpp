#ifndef __PROTOTYPE_PRODUCT_HPP__
#define __PROTOTYPE_PRODUCT_HPP__

#include <memory>
#include <string>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::string;

    class Product
    {
    public:
        void use(const string& s) { this->useImpl(s); };
        shared_ptr<Product> createClone() { return this->createCloneImpl(); };

    protected:
        virtual void useImpl(const string& s) = 0;
        virtual shared_ptr<Product> createCloneImpl() = 0;
    };
}

#endif