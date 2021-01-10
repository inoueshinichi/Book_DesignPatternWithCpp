#ifndef DECORATOR_SIDEBORDER_HPP
#define DECORATOR_SIDEBORDER_HPP

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

    class DP_API SideBorder : public Border
    {
        char border_char_;

    public:
        SideBorder(shared_ptr<DecoBaseDisplay> display, char ch)
            : Border(display) , border_char_(ch)
        {}
        
        virtual ~SideBorder() {}

        virtual int getColumns() override
        {
            return 1 + display_->getColumns() + 1;
        }

        virtual int getRows() override
        {
            return display_->getRows();
        }

        virtual string getRowText(int row) override
        {
            stringstream ss;
            ss << border_char_ << display_->getRowText(row) << border_char_;
            return ss.str();
        } 
    };
}
#endif