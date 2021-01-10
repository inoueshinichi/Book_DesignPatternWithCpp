#ifndef DECORATOR_FULLBORDER_HPP
#define DECORATOR_FULLBORDER_HPP

#include "../common.hpp"
#include "border.hpp"

#include <memory>
#include <string>
#include <sstream>

namespace Is
{
    using std::shared_ptr;
    using std::string;
    using std::stringstream;

    class DP_API FullBorder : public Border
    {
        string makeLine(char ch, int count)
        {
            stringstream ss;
            for (int i = 0; i < count; ++i)
            {
                ss << ch;
            }
            return ss.str();
        }

    public:
        FullBorder(shared_ptr<DecoBaseDisplay> display) : Border(display) {}
        virtual ~FullBorder() {}

        virtual int getColumns() override
        {
            return 1 + display_->getColumns() + 1;
        }

        virtual int getRows() override
        {
            return 1 + display_->getRows() + 1;
        }

        virtual string getRowText(int row) override
        {
            using namespace std::literals::string_literals;
            stringstream ss;

            if (row == 0)
            {
                ss << "+"s << makeLine('-', display_->getColumns()) << "+"s;
                return ss.str();
            }
            else if (row == display_->getRows() + 1)
            {
                ss << "+"s << makeLine('-', display_->getColumns()) << "+"s;
                return ss.str();
            }
            else
            {
                ss << "|"s << display_->getRowText(row - 1) << "|"s;
                return ss.str();
            }
        }
    };
}
#endif