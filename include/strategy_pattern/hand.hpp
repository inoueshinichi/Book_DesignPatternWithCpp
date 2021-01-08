#ifndef STRATEGY_HAND_HPP
#define STRATEGY_HAND_HPP

#include "../common.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API Hand
    {
        int hand_value_;

        int fight(Hand h) const
        {
            // 引き分けは: 0
            // thisの勝ち: 1
            // thisの負け: -1

            if (this->hand_value_ == h.hand_value_)
            {
                return 0;
            }
            else if ((this->hand_value_ + 1) % 3 == h.hand_value_)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

    public:
        static const int HAND_VALUE_GUU = 0;   // グー
        static const int HAND_VALUE_CHOKI = 1; // チョキ
        static const int HAND_VALUE_PAA = 2;   // パー
        static const Hand hand[];
        static const string name[];

        Hand() : hand_value_(0) {}
        Hand(int hand_value) : hand_value_(hand_value) {}
        ~Hand() {}

        static Hand getHand(int hand_value)
        {
            return hand[hand_value];
        }

        bool isStrongerThan(Hand h) const
        {
            return fight(h) == 1; // thisがhより強いときtrue
        }

        bool isWeakerThan(Hand h) const
        {
            return fight(h) == -1; // thisがhより弱いときtrue
        }    

        const string& toString() const
        {
            return name[hand_value_];
        }
    };
}
#endif