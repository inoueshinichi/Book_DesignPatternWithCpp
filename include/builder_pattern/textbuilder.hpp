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
        void makeTitle(const string& title) override;
        void makeString(const string& str) override;
        void makeItems(const vector<string>& items) override;
        void close();
        string getResult() { return ss.str(); }
    };
}

#endif