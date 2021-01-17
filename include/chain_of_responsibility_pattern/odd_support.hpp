#ifndef CHAIN_OF_RESPONSIBILITY_ODDSUPPORT_HPP
#define CHAIN_OF_RESPONSIBILITY_ODDSUPPORT_HPP

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

    class DP_API OddSupport : public Support
    {
    public:
        OddSupport(const string& name) : Support(name) {}
        virtual ~OddSupport() {}

    protected:
        virtual bool resolve_impl(shared_ptr<Trouble> trouble) override final
        {
            if (trouble->getNumber() % 2 == 1)
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
            return "OddSupport";
        }
    };
}
#endif