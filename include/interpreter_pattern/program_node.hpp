#ifndef INTERPRETPER_PROGRAM_NODE_HPP
#define INTERPRETPER_PROGRAM_NODE_HPP

#include "../common.hpp"
#include "node.hpp"
#include "command_list_node.hpp"

#include <vector>
#include <string>
#include <memory>

namespace Is
{
    using std::vector;
    using std::string;
    using std::shared_ptr;
    using std::make_shared;

    // <program> ::= program <command list>
    class DP_API ProgramNode : public Node
    {
        shared_ptr<Node> command_list_node_;
    public:
        ProgramNode() {}
        virtual ~ProgramNode() {}

        virtual void parse(InterpreterContext& ctx) noexcept(false) override final 
        {
            ctx.skip_token("program");
            command_list_node_ = make_shared<CommandListNode>();
            command_list_node_->parse(ctx);
        }

        virtual string to_string() const override final
        {
            return "[program " + command_list_node_->to_string() + "]";
        }
    };
}
#endif