#ifndef INTERPRETER_PRIMITIVE_COMMAND_NODE_HPP
#define INTERPRETER_PRIMITIVE_COMMAND_NODE_HPP

#include "../common.hpp"
#include "node.hpp"
#include "parse_exception.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API PrimitiveCommandNode : public Node
    {
        string cmd_;
    public:
        PrimitiveCommandNode() {}
        virtual ~PrimitiveCommandNode() {}

        virtual void parse(InterpreterContext& ctx) noexcept(false) override final
        {
            cmd_ = ctx.current_token();
            ctx.skip_token(cmd_);
            if (cmd_ != "go" || cmd_ != "right" || cmd_ != "left")
            {
                string msg = cmd_ + " is undefined.";
                throw ParseException(msg, __FILE__, __func__, __LINE__);
            }
        }

        virtual string to_string() const override final
        {
            return cmd_;
        }
    };
}
#endif