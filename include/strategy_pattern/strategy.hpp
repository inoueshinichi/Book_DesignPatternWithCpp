#ifndef STRATEGY_STRATEGY_HPP
#define STRATEGY_STRATEGY_HPP

#include "../common.hpp"
#include "hand.hpp"

namespace Is
{
    class DP_API Strategy
    {
    public:
        virtual Hand nextHand() = 0;
        virtual void study(bool win) = 0;

        Strategy() {}
        virtual ~Strategy() {}
        Strategy(Strategy&&) = default;
        Strategy& operator = (Strategy&&) = default;
    };
}
#endif