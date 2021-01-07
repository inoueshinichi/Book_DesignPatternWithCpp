#ifndef BRIDGE_COUNT_DISPLAY_HPP
#define BRIDGE_COUNT_DISPLAY_HPP

#include "../common.hpp"
#include "display.hpp"

#include <memory>

namespace Is
{
    using std::unique_ptr;

    class DP_API CountDisplay : public Display
    {
    public:
        CountDisplay(unique_ptr<DisplayImpl>&& impl) : Display(std::move(impl)) {}
        virtual ~CountDisplay() {}

        virtual void multiDisplay(int times)
        {
            open();
            for (int i = 0; i < times; ++i)
            {
                print();
            }
            close();
        }
    };
}
#endif