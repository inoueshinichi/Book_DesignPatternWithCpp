#ifndef ABSTRACT_FACTORY_TABLE_TRAY_HPP
#define ABSTRACT_FACTORY_TABLE_TRAY_HPP

#include "../../common.hpp"
#include "../tray.hpp"

#include <string>
#include <sstream>
#include <memory>

namespace Is
{
    using std::string;
    using std::stringstream;
    using std::shared_ptr;

    class DP_API TableTray : public Tray
    {
    public:
        TableTray(const string& caption) : Tray(caption) {}

        virtual string makeHTML() override
        {
            stringstream ss;
            ss << "<td>";
            ss << "<table width=\"100%\" border=\"1\"><tr>";
            ss << "<td bgcolor=\"#cccccc\" align=\"center\" colspan=\"";
            ss << tray_.size() << "\"><b>" << caption_ << "</b></td>";
            ss << "</tr>\n";
            ss << "<tr>\n";

            auto iter = tray_.begin();
            while (iter != tray_.end())
            {
                auto item = *iter;
                ss << item->makeHTML();
                ++iter;
            }
            ss << "</tr></table>";
            ss << "</td>";
            return ss.str();
        }
    };
}

#endif