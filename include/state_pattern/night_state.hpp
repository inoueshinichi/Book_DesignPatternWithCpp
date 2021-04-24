#ifndef STATE_NIGHT_STATE_HPP
#define STATE_NIGHT_STATE_HPP

#include "../common.hpp"
#include "state.hpp"
#include "state_singleton_manager.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API NightState : public State
    {
    	friend StateSingletonManager;
    	NightState() {}
    public:
    	virtual ~NightState() {}
    	NightState(const NightState&) = delete;
    	NightState& operator=(const NightState&) = delete;
    	
        virtual void doClock(Context* ctx, int hour) override final;
        virtual void doUse(Context* ctx) override final;
        virtual void doAlarm(Context* ctx) override final;
        virtual void doPhone(Context* ctx) override final;

        virtual string operator()() override final
        {
            return "[夜間]";
        }
    };
}
#endif
