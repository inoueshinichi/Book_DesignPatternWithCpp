#ifndef FLYWEIGHT_BIGCHAR_FACTORY_HPP
#define FLYWEIGHT_BIGCHAR_FACTORY_HPP

#include "../common.hpp"
#include "flyweight_singleton_manager.hpp"


#include <map>
#include <string>
#include <memory>

namespace Is
{
    using std::map;
    using std::string;
    using std::shared_ptr;
    using std::make_shared;

    class BigChar;

    class DP_API BigCharFactory
    {
        map<const char, shared_ptr<BigChar>> pool_;

        friend FlyweightSingletonManager;
        BigCharFactory() {}
    public:
        ~BigCharFactory() {}
        BigCharFactory(const BigCharFactory&) = delete;
        BigCharFactory& operator=(const BigCharFactory&) = delete;

        shared_ptr<BigChar> getBigChar(const char& char_name, const string& dir);
    };
}
#endif