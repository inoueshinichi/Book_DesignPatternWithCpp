#ifndef PROTOTYPE_PRODUCT_HPP
#define PROTOTYPE_PRODUCT_HPP

#include "../common.hpp"

#include <memory>
#include <string>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::string;

    class DP_API Product
    {
    public:
        virtual ~Product() {}
        void use(const string& s) { this->useImpl(s); }
        shared_ptr<Product> createClone() { return this->createCloneImpl(); }

    protected:
        virtual void useImpl(const string& s) = 0;
        virtual shared_ptr<Product> createCloneImpl() = 0;
    };
}
#endif
