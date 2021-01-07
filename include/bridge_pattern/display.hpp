#ifndef BRIDGE_DISPLAY_HPP
#define BRIDGE_DISPLAY_HPP

#include "../common.hpp"
#include "displayimpl.hpp"

#include <memory>

namespace Is
{
    using std::unique_ptr;

    class DP_API Display
    {
        unique_ptr<DisplayImpl> impl_;

    public:
        Display(unique_ptr<DisplayImpl>&& impl) : impl_(std::move(impl)) {}
        virtual ~Display() {}

        virtual void open()
        {
            impl_->rawOpen();
        }

        virtual void print()
        {
            impl_->rawPrint();
        }

        virtual void close()
        {
            impl_->rawClose();
        }

        void display()
        {
            open();
            print();
            close();
        }
    };
}
#endif