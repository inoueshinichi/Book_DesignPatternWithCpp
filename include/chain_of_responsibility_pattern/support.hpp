#ifndef CHAIN_OF_RESPONSIBILITY_SUPPORT_HPP
#define CHAIN_OF_RESPONSIBILITY_SUPPORT_HPP

#include "../common.hpp"
#include "trouble.hpp"

#include <memory>
#include <string>
#include <sstream>
#include <iostream>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::string;
    using std::stringstream;

    class DP_API Support
    {
        string name_;
        shared_ptr<Support> next_;

    public:
        Support(const string& name) : name_(name) {}
        virtual ~Support() {}

        shared_ptr<Support> setNext(shared_ptr<Support> next)
        {
            next_ = next;
            return next_;
        }

        void support(shared_ptr<Trouble> trouble)
        {
            if (resolve(trouble))
            {
                done(trouble);
            }
            else if (next_ != nullptr)
            {
                next_->support(trouble);
            }
            else
            {
                fail(trouble);
            }
        }

        string getName()
        {
            return getName_impl();
        }

        bool resolve(shared_ptr<Trouble> trouble)
        {
            return this->resolve_impl(trouble);
        }

    protected:
        virtual string getName_impl() = 0;
        virtual bool resolve_impl(shared_ptr<Trouble> trouble) = 0;

        void done(shared_ptr<Trouble> trouble)
        {
            std::cout << trouble->toString() << " is resolved by " << getName() << " [" << name_ << "]" << "." << std::endl;
        }

        void fail(shared_ptr<Trouble> trouble)
        {
            std::cout << trouble->toString() << " cannot be resolved." << std::endl;
        }

    };
}
#endif