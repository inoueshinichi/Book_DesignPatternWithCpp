#ifndef INTERPRETER_COMMAND_NODE_HPP
#define INTERPRETER_COMMAND_NODE_HPP

#include "../common.hpp"
#include "node.hpp"
#include "repeat_command_node.hpp"
#include "primitive_command_node.hpp"

#include <string>
#include <memory>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::string;

    // <command> ::= <repeat command> | <primitive command>
    class DP_API CommandNode : public Node
    {
        shared_ptr<Node> node_;
    public:
        CommandNode() {}
        virtual ~CommandNode() {}

        virtual void parse(InterpreterContext& ctx) noexcept(false) override final
        {
            if (ctx.current_token() == "repeat")
            {
                node_ = make_shared<RepeatCommandNode>();
                node_->parse(ctx);
            }
            else {
                node_ = make_shared<PrimitiveCommandNode>();
                node_->parse(ctx);
            }
        }

        virtual string to_string() const override final
        {
            return node_->to_string();
        }

    };
}
#endif