#ifndef COMMAND_MACROCOMMAND_HPP
#define COMMAND_MACROCOMMAND_HPP

#include "../common.hpp"
#include "command.hpp"

#include <deque>
#include <memory>

namespace Is
{
    using std::deque;
    using std::shared_ptr;

    class DP_API MacroCommand : public Command
    {
        deque<shared_ptr<Command>> commands_;
    public:
        MacroCommand() {}
        virtual ~MacroCommand() {}

        virtual void execute() override final
        {
            for (std::size_t i = 0; i < commands_.size(); ++i)
            {
                commands_.at(i)->execute();
            }
        }

        void append(shared_ptr<Command> cmd)
        {
            if (cmd.get() != this)
            {
                commands_.push_back(cmd);
            }
        }

        void undo()
        {
            if (!commands_.empty())
            {
                commands_.pop_back();
            }
        }

        void clear()
        {
            commands_.clear();
        }

    };
}
#endif