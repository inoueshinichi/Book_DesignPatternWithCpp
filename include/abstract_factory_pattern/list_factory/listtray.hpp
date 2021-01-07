#ifndef ABSTRACT_FACTORY_LIST_TRAY_HPP
#define ABSTRACT_FACTORY_LIST_TRAY_HPP

#include "../../common.hpp"
#include "../tray.hpp"

#include <string>
#include <sstream>
#include <memory>

namespace Is
{
    using std::string;
    using std::shared_ptr;

    class DP_API ListTray : public Tray
    {
    public:
        ListTray(const string& caption) : Tray(caption) {}
        virtual ~ListTray() {}

        virtual string makeHTML() override
        {
            std::stringstream ss;
            ss << "<li>" << std::endl;
            ss << caption_ << std::endl;
            ss << "<ul>" << std::endl;
            
            auto iter = tray_.begin();
            while (iter != tray_.end())
            {
                ss << (*iter)->makeHTML(); // shared_ptr<Tray>
                ++iter;
            }
            ss << "</ul>" << std::endl;
            ss << "</li>" << std::endl;

            return ss.str();
        }
    };
}
#endif