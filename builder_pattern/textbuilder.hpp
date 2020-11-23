#ifndef __TEXTBUILDER_HPP__
#define __TEXTBUILDER_HPP__

#include "builder.hpp"

#include <string>
#include <sstream>
#include <memory>

namespace Is
{
    using std::shared_ptr;
    using std::string;
    using std::stringstream;

    class TextBuilder : public Builder
    {
        stringstream ss;

    public:
        void makeTitle(const string& title) override
        {
            ss << "==============================" << std::endl;
            ss << " 『" << title << "』" << std::endl;
            ss << std::endl;
        }

        void makeString(const string& str) override
        {
            ss << "■ " << str << std::endl;
            ss << std::endl;
        }

        void makeItems(const vector<string>& items) override
        {
            for (int i = 0; i < items.size(); ++i)
            {
                ss << "  ・" << items.at(i) << std::endl;
            }
            ss << std::endl;
        }

        void close()
        {
            ss <<  "==============================" << std::endl;
        }

        string getResult()
        {
            return ss.str();
        }
    };
}

#endif