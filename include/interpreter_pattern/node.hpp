#ifndef INTERPERTER_NODE_HPP
#define INTERPERTER_NODE_HPP

#include "../common.hpp"
#include "parse_exception.hpp"
#include "interpreter_context.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API Node
    {
    public:
        Node() {}
        virtual ~Node() {}

        virtual void parse(InterpreterContext& ctx) noexcept(false) = 0;
        virtual string to_string() const = 0;
    };
}
#endif