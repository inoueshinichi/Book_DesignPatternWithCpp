#ifndef CHAIN_OF_RESPONSIBILITY_LIMITSUPPORT_HPP
#define CHAIN_OF_RESPONSIBILITY_LIMITSUPPORT_HPP

#include "../common.hpp"
#include "support.hpp"

#include <memory>
#include <string>
#include <sstream>

namespace Is
{
    using std::shared_ptr;
    using std::string;
    using std::stringstream;

    class DP_API LimitSupport : public Support
    {
        int limit_;

    public:
        LimitSupport(const string& name, int limit) : Support(name), limit_(limit) {}
        virtual ~LimitSupport() {}

    protected:
        virtual bool resolve_impl(shared_ptr<Trouble> trouble) override final
        {
            if (trouble->getNumber() < limit_)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        virtual string getName_impl() override final
        {
            return "LimitSupport";
        }
    };
}
#endif