#ifndef STRATEGY_PROBSTRATEGY_HPP
#define STRATEGY_PROBSTRATEGY_HPP

#include "../common.hpp"
#include "strategy.hpp"

#include <random>

namespace Is
{
    class DP_API ProbStrategy : public Strategy
    {
        std::mt19937_64 engine_; // 64bit版メルセンヌツイスターエンジン
        int prevHandValue_ { 0 };
        int currentHandValue_ { 0 };
        int history_[3][3] = {
                { 1, 1, 1 },
                { 1, 1, 1 },
                { 1, 1, 1 }
            };

        int getSum(int hand_value)
        {
            int sum {0};
            for (int i = 0; i < 3; ++i)
            {
                sum += history_[hand_value][i];
            }
            return sum;
        }

    public:
        ProbStrategy(int seed)
        {
            // 乱数シードを設定
            engine_.seed(seed);
        }

        virtual ~ProbStrategy() {}

        virtual Hand nextHand() 
        {
            int range_max = getSum(currentHandValue_);
            std::uniform_int_distribution<int> dist(0, range_max);
            int bet = dist(engine_);
            int hand_value = 0;

            if (bet < history_[currentHandValue_][0])
            {
                hand_value = 0; // グー
            }
            else if (bet < history_[currentHandValue_][1])
            {
                hand_value = 1; // チョキ
            }
            else
            {
                hand_value = 2; // パー
            }

            prevHandValue_ = currentHandValue_;
            currentHandValue_ = hand_value;
            return Hand::getHand(hand_value); // 右辺値
        }

        virtual void study(bool win)
        {
            if (win)
            {
                history_[prevHandValue_][currentHandValue_] += 1;
            }
            else
            {
                history_[prevHandValue_][(currentHandValue_ + 1) % 3] += 1;
                history_[prevHandValue_][(currentHandValue_ + 1) % 3] += 1;
            }
        }
    };
}
#endif