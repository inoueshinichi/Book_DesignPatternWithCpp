#ifndef __HTMLBUILDER_HPP__
#define __HTMLBUILDER_HPP__

#include "builder.hpp"

#include <memory>
#include <string>
#include <vector>
#include <fstream>


namespace Is
{
    using std::string;
    using std::ofstream;

    class HTMLBuilder : public Builder
    {
        string filename;
        ofstream ofs;

    public:
        void makeTitle(const string& title) override;
        void makeString(const string& str) override;
        void makeItems(const vector<string>& items) override;
        void close() override;
        string getResult() { return filename; };
    };
}

#endif