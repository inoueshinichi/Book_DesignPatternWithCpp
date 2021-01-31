#include "flyweight_pattern/bigcharfactory.hpp"
#include "flyweight_pattern/flyweight_singleton_manager-internal.hpp"
#include "flyweight_pattern/bigchar.hpp"

namespace Is
{
    shared_ptr<BigChar> BigCharFactory::getBigChar(const char& char_name, const string& dir)
    {
        if (!pool_.contains(char_name))
        {
            auto bigchar = make_shared<BigChar>(char_name, dir);
            pool_.insert({char_name, bigchar});
        }
        return pool_[char_name];
    }

    FLYWEIGHT_INSTANTIATE_SINGLETON(DP_API, BigCharFactory);
}