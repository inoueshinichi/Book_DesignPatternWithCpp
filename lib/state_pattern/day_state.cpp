#include "state_pattern/day_state.hpp"
#include "state_pattern/night_state.hpp"
#include "state_pattern/state_singleton_manager-internal.hpp"
#include "state_pattern/context.hpp"

namespace Is
{
    void DayState::doClock(Context* ctx, int hour)
    {
        if (hour < 9 || 17 <= hour)
        {
            ctx->changeState(StateSingletonManager::getInstance<NightState>());
        }
    }

    void DayState::doUse(Context* ctx)
    {
        ctx->recordLog("金庫使用（昼間）");
    }

    void DayState::doAlarm(Context* ctx)
    {
        ctx->callSecurityCenter("非常ベル（昼間）");
    }

    void DayState::doPhone(Context* ctx)
    {
        ctx->callSecurityCenter("通常の通話（昼間）");
    }

    STATE_INSTANTIATE_SINGLETON(DP_API, DayState);
}