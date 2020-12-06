#ifndef BUILDER_TEXTBUILDER_HPP
#define BUILDER_TEXTBUILDER_HPP

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
        void close() override;
        string getResult() { return ss.str(); }
    };
}
#endif
