#ifndef INTERPRETER_REPEAT_COMMAND_NODE_HPP
#define INTERPRETER_REPEAT_COMMAND_NODE_HPP

#include "../common.hpp"
#include "node.hpp"
#include "command_list_node.hpp"

#include <memory>
#include <string>

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::make_shared;

    class DP_API RepeatCommandNode : public Node
    {
        shared_ptr<Node> command_list_node_;
        int repeat_num_;
    public:
        RepeatCommandNode() {}
        virtual ~RepeatCommandNode() {}

        virtual void parse(InterpreterContext& ctx) noexcept(false) override final
        {
            ctx.skip_token("repeat");
            repeat_num_ = ctx.current_number();
            ctx.next_token();
            command_list_node_ = make_shared<CommandListNode>();
            command_list_node_->parse(ctx);
        }

        virtual string to_string() const override final
        {
            return "[repeat " + std::to_string(repeat_num_) + command_list_node_->to_string() + "]";
        }
    };
}
#endif