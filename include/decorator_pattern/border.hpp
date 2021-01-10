#ifndef DECORATOR_BORDER_HPP
#define DECORATOR_BORDER_HPP

#include "../common.hpp"
#include "display.hpp"

#include <memory>

namespace Is
{
    using std::shared_ptr;

    class DP_API Border : public DecoBaseDisplay
    {
    protected:
        shared_ptr<DecoBaseDisplay> display_;

        Border(shared_ptr<DecoBaseDisplay> display) : display_(display) {}
        virtual ~Border() {}       
    };
}
#endif