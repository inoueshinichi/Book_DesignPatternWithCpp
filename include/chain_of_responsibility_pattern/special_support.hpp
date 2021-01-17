#ifndef CHAIN_OF_RESPONSIBILITY_SPECIALSUPPORT_HPP
#define CHAIN_OF_RESPONSIBILITY_SPECIALSUPPORT_HPP

#include "../common.hpp"
#include "support.hpp"

#include <memory>
#include <string>
#include <sstream>

namespace Is
{
    using std::string;
    using std::stringstream;
    using std::shared_ptr;

    class DP_API SpecialSupport : public Support
    {
        int number_;

    public:
        SpecialSupport(const string& name, int number) : Support(name), number_(number) {}
        virtual ~SpecialSupport() {}

    protected:
        virtual bool resolve_impl(shared_ptr<Trouble> trouble) override final
        {
            if (trouble->getNumber() == number_)
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
            return "SpecialSupport";
        }
    };
}
#endif