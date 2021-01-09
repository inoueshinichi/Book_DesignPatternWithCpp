#ifndef STRATEGY_WINNINGSTRATEGY_HPP
#define STRATEGY_WINNINGSTRATEGY_HPP

#include "../common.hpp"
#include "strategy.hpp"

#include <random>

namespace Is
{
    class DP_API WinningStrategy : public Strategy
    {
        std::mt19937_64 engine_; // 64bit版メルセンヌツイスター乱数エンジン
        bool won_ {false};
        Hand prevHand_;

    public:
        WinningStrategy(int seed)
        {
            // 乱数シードを設定
            engine_.seed(seed);
        }

        virtual ~WinningStrategy() {}


        virtual Hand nextHand() override
        {
            if (!won_)
            {
                std::uniform_int_distribution<int> d(0, 3); // 一様分布
                prevHand_ = Hand::getHand(d(engine_));      // 乱数生成
            }

            return prevHand_; // 勝っていたらなら、前回の手を出す(愚策)
        }

        virtual void study(bool win) override
        {
            won_ = win;
        }
    };
}
#endif