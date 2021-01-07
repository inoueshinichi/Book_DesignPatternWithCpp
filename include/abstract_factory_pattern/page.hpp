#ifndef ABSTRACT_FACTORY_PAGE_HPP
#define ABSTRACT_FACTORY_PAGE_HPP

#include "../common.hpp"
#include "item.hpp"

#include <string>
#include <list>
#include <memory>
#include <fstream>
#include <iostream>
#include <exception>

namespace Is
{
    using std::string;
    using std::list;
    using std::shared_ptr;
    using std::ofstream;

    class DP_API Page
    {
    protected:
        string title_;
        string author_;
        list<shared_ptr<Item>> content_;

    public:
        Page(const string& title, const string& author) : title_(title), author_(author) {}
        void add(shared_ptr<Item> item) { content_.push_back(item); }
        
        void output()
        {
            try
            {
                string filename = title_ + ".html";

                ofstream ofs(filename, std::ios::out);
                if (!ofs.fail())
                {
                    ofs << this->makeHTML();
                    std::cout << filename << " を作成しました." << std::endl;
                }   
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        virtual string makeHTML() = 0;
    };
}
#endif