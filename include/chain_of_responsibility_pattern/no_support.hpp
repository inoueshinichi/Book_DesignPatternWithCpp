#ifndef CHAIN_OF_RESPONSIBILITY_HPP
#define CHAIN_OF_RESPONSIBILITY_HPP

#include "../common.hpp"
#include "support.hpp"

#include <string>
#include <memory>

namespace Is
{
    using std::string;
    using std::shared_ptr;

    class DP_API NoSupport : public Support
    {
    public:
        NoSupport(const string& name) : Support(name) {}
        virtual ~NoSupport() {}

    protected:
        virtual bool resolve_impl(shared_ptr<Trouble> trouble) override final
        {
            return false;
        }

        virtual string getName_impl() override final
        {
            return "NoSupport";
        }
    };
}
#endif