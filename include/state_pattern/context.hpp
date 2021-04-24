#ifndef STATE_CONTEXT_HPP
#define STATE_CONTEXT_HPP

#include "../common.hpp"

#include <string>

namespace Is
{
    using std::string;

    class State;

    class DP_API Context
    {
    public:
        Context() {}
        virtual ~Context() {}

        virtual void setClock(int hour) = 0;
        virtual void changeState(State* state) = 0;
        virtual void callSecurityCenter(const string& msg) = 0;
        virtual void recordLog(const string& msg) = 0;
    };
}
#endif 