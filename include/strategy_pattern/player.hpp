#ifndef STRATEGY_PLAYER_HPP
#define STRATEGY_PLAYER_HPP

#include "../common.hpp"
#include "strategy.hpp"

#include <string>
#include <memory>
#include <sstream>

namespace Is
{
    using std::string;
    using std::unique_ptr;
    using std::stringstream;

    class DP_API Player
    {
        string name_;
        unique_ptr<Strategy> strategy_;
        int win_count_{0};
        int lose_count_{0};
        int game_count_{0};

    public:
        Player(const string& name, unique_ptr<Strategy>&& strategy)
            : name_(name), strategy_(std::move(strategy))
        {}

        Hand nextHand()
        {
            return strategy_->nextHand(); // Strategyにお伺いを立てる
        }

        void win()
        {
            strategy_->study(true);
            win_count_++;
            game_count_++;
        }

        void lose()
        {
            strategy_->study(false);
            lose_count_++;
            game_count_++;
        }

        void even()
        {
            game_count_++;
        }

        string toString() 
        {
            using namespace std::literals::string_literals;
            stringstream ss;
            ss << "["s << name_ << ":"s;
            ss << game_count_ << " games, "s;
            ss << win_count_ << " win, "s;
            ss << lose_count_ << " lose]"s;
            return ss.str();
        }
    };
}
#endif