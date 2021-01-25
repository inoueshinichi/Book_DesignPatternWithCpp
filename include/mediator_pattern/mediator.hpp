#ifndef MEDIATOR_MEDIATOR_HPP
#define MEDIATOR_MEDIATOR_HPP

#include "../common.hpp"

namespace Is
{
    class DP_API Mediator
    {
    public:
        Mediator() {}
        virtual ~Mediator() {}

        virtual void createColleagues() = 0;
        virtual void colleagueChanged() = 0;
    };
}
#endif