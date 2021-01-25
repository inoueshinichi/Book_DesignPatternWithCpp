#ifndef MEDIATOR_COLLEAGUE_HPP
#define MEDIATOR_COLLEAGUE_HPP

#include "../common.hpp"

namespace Is
{
    class Mediator;

    class DP_API Colleague
    {
    public:
        Colleague() {}
        virtual ~Colleague() {}

        virtual void setMediator(Mediator* mediator) = 0;
        virtual void setColleagueEnabled(bool enabled) = 0;
    };
}

using namespace Is;

#endif