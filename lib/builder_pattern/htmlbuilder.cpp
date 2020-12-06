#include "builder_pattern/htmlbuilder.hpp"


namespace Is
{
    void HTMLBuilder::makeTitle(const string& title) 
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

    void HTMLBuilder::makeString(const string& str) 
    {
        ofs << "<p>" << str << "</p>" << std::endl;
    }

    void HTMLBuilder::makeItems(const vector<string>& items) 
    {
        ofs << "<ul>" << std::endl;
        for (size_t i = 0; i < items.size(); ++i)
        {
            ofs << "<li>" << items.at(i) << "</li>" << std::endl;
        }
        ofs << "</ul>" << std::endl;
    }

    
    void HTMLBuilder::close() 
    {
        ofs << "</body></html>" << std::endl;
        ofs.close();
    }
}
