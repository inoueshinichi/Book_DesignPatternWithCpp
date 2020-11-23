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

        void makeTitle(const string& title) override
        {
            filename = title + string(".html");
        
            ofs = ofstream(filename, std::ios::out); // 上書き出し
            if (!ofs.fail())
            {
                ofs << "<html><head><title>" << title << "</title></head><body>" << std::endl;
                // タイトル出力
                ofs << "<h1>" << title << "</h1>" << std::endl;
            }
            
        }

        void makeString(const string& str) override
        {
            ofs << "<p>" << str << "</p>" << std::endl;
        }

        void makeItems(const vector<string>& items) override
        {
            ofs << "<ul>" << std::endl;
            for (int i = 0; i < items.size(); ++i)
            {
                ofs << "<li>" << items.at(i) << "</li>" << std::endl;
            }
            ofs << "</ul>" << std::endl;
        }

        void close() override
        {
            ofs << "</body></html>" << std::endl;
            ofs.close();
        }

        string getResult()
        {
            return filename;
        }
    };
}

#endif