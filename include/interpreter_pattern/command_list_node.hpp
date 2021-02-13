#ifndef INTERPRETER_COMMAND_LIST_NODE_HPP
#define INTERPRETER_COMMAND_LIST_NODE_HPP

#include "../common.hpp"
#include "node.hpp"
#include "command_node.hpp"
#include "parse_exception.hpp"

#include <list>
#include <memory>
#include <string>
#include <sstream>

namespace Is
{
    using std::list;
    using std::shared_ptr;
    using std::make_shared;
    using std::string;
    using std::stringstream;

    // <command list> ::= <command>* end
    class DP_API CommandListNode : public Node
    {
        list<shared_ptr<Node>> list_node_;
    public:
        CommandListNode() {}
        virtual ~CommandListNode() {}

        virtual void parse(InterpreterContext& ctx) noexcept(false) override final
        {
            while (true) {
                if (ctx.current_token().empty()) {
                    throw ParseException("Missing `end`", __FILE__, __func__, __LINE__);
                }
                else if (ctx.current_token() == "end") {
                    ctx.skip_token("end");
                    break;
                }
                else {
                    auto command_node = make_shared<CommandNode>();
                    command_node->parse(ctx);
                    list_node_.push_back(std::move(command_node));
                }
            }
        }

        virtual string to_string() const override final
        {
            stringstream ss;
            for (const auto& node : list_node_)
            {
                ss << node->to_string();
            }
            return ss.str();
        }
    };
}
#endif