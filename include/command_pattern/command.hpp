#ifndef COMMAND_COMMAND_HPP
#define COMMAND_COMMAND_HPP

#include "../common.hpp"

namespace Is
{
    class DP_API Command
    {
    public:
        Command() {}
        virtual ~Command() {}

        virtual void execute() = 0;
    };
}
#endif