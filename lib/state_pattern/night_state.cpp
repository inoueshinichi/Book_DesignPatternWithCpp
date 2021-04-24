#include "state_pattern/night_state.hpp"
#include "state_pattern/day_state.hpp"
#include "state_pattern/state_singleton_manager-internal.hpp"
#include "state_pattern/context.hpp"

namespace Is
{
    void NightState::doClock(Context* ctx, int hour)
    {
        if (9 <= hour && hour < 17)
        {
            ctx->changeState(StateSingletonManager::getInstance<DayState>());
        }
    }

    void NightState::doUse(Context* ctx)
    {
        ctx->callSecurityCenter("非常：夜間の金庫使用！");
    }

    void DayState::doAlarm(Context* ctx)
    {
        ctx->callSecurityCenter("非常ベル（夜間）");
    }

    void NightState::doPhone(Context* ctx)
    {
        ctx->recordLog("夜間の通話録音");
    }

    STATE_INSTANTIATE_SINGLETON(DP_API, NightState);
}