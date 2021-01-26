#ifndef OBSERVER_OBSERVER_HPP
#define OBSERVER_OBSERVER_HPP

#include "../common.hpp"

#include <memory>

namespace Is
{
    using std::shared_ptr;

    class NumberGenerator;

    class DP_API Observer
    {
    public:
        Observer() {}
        virtual ~Observer() {}

        virtual void update(shared_ptr<NumberGenerator> generator) = 0;
    };
}
#endif