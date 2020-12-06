#include "builder_pattern/textbuilder.hpp"


namespace Is
{
    void TextBuilder::makeTitle(const string& title) 
    {
        ss << "==============================" << std::endl;
        ss << " 『" << title << "』" << std::endl;
        ss << std::endl;
    }


    void TextBuilder::makeString(const string& str) 
    {
        ss << "■ " << str << std::endl;
        ss << std::endl;
    }


    void TextBuilder::makeItems(const vector<string>& items) 
    {
        for (size_t i = 0; i < items.size(); ++i)
        {
            ss << "  ・" << items.at(i) << std::endl;
        }
        ss << std::endl;
    }


    void TextBuilder::close()
    {
        ss <<  "==============================" << std::endl;
    }
}
