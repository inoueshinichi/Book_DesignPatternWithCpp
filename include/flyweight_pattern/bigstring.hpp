#ifndef FLYWEIGHT_BIGSTRING_HPP
#define FLYWEIGHT_BIGSTRING_HPP

#include "../common.hpp"
#include "bigchar.hpp"
#include "bigcharfactory.hpp"
#include "flyweight_singleton_manager-internal.hpp"

#include <vector>
#include <memory>
#include <string>

namespace Is
{
    using std::vector;
    using std::shared_ptr;
    using std::string;

    class DP_API BigString
    {
        vector<shared_ptr<BigChar>> bigchars_;

    public:
        BigString(const string& str, const string& dir)
        {
            bigchars_.resize(str.length());
            auto factory = FlyweightSingletonManager::getInstance<BigCharFactory>();
            for (size_t i = 0; i < bigchars_.size(); ++i)
            {
                auto bigchar = factory->getBigChar(str[i], dir);
                bigchars_[i] = bigchar;
            }
        }

        void print()
        {
            for (auto& bigchar : bigchars_)
            {
                bigchar->print();
            }
        }
    };
}
#endif