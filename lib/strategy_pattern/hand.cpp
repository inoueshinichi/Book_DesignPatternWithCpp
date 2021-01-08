#include "strategy_pattern/hand.hpp"

namespace Is
{
    using namespace std::literals::string_literals;

    const Hand Hand::hand[] = {
        Hand(Hand::HAND_VALUE_GUU),
        Hand(Hand::HAND_VALUE_CHOKI),
        Hand(Hand::HAND_VALUE_PAA)
    };

    const string Hand::name[] = {
        u8"グー"s,
        u8"チョキ"s,
        u8"パー"s
    };
}