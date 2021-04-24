#ifndef STATE_STATE_HPP
#define STATE_STATE_HPP

#include "../common.hpp"

#include <string>

namespace Is
{
    using std::string;

    class Context;

    class DP_API State
    {
    protected:
        State() {}
        State(const State&) = delete;
        State& operator=(const State&) = delete;
        
    public:
        virtual ~State() {}
        virtual void doClock(Context* ctx, int hour) = 0;
        virtual void doUse(Context* ctx) = 0;
        virtual void doAlarm(Context* ctx) = 0;
        virtual void doPhone(Context* ctx) = 0;
        virtual string operator()() = 0;
    };
}
#endif
