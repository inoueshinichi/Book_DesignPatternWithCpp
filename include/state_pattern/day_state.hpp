#ifndef STATE_DAY_STATE_HPP
#define STATE_DAY_STATE_HPP

#include "../common.hpp"
#include "state.hpp"
#include "state_singleton_manager.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API DayState : public State
    {
    	friend StateSingletonManager;
    	DayState() {}
    public:
    	virtual ~DayState() {}
    	DayState(const DayState&) = delete;
    	DayState& operator=(const DayState&) = delete;
    	
        virtual void doClock(Context* ctx, int hour) override final;
        virtual void doUse(Context* ctx) override final;
        virtual void doAlarm(Context* ctx) override final;
        virtual void doPhone(Context* ctx) override final;

        virtual string operator()()
        {
            return "[昼間]";
        }
    };
}
#endif
