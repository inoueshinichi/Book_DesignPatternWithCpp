#ifndef COMPOSITE_DIRECTORY_HPP
#define COMPOSITE_DIRECTORY_HPP

#include "../common.hpp"
#include "entry.hpp"

#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <iterator>

namespace Is
{
    using std::string;
    using std::vector;
    using std::shared_ptr;

    class DP_API Directory : public Entry
    {
        string name_;
        vector<shared_ptr<Entry>> directory_;

    protected:
        virtual void printList_impl(const string& prefix) override
        {
            stringstream ss;
            ss << prefix << "/" << getName();
            std::cout << ss.str() << std::endl;

            for (const auto& entry : directory_)
            {
                entry->printList(ss.str()); // Entry : File or Directory
                // EntryクラスのポインタからはprintList(const string& prefx)しかアクセスできない.
            }
        }

    public:
        Directory(const string& name) : name_(name) 
        {}
        virtual ~Directory() {}

        virtual string getName_impl() override
        {
            return name_;
        }

        virtual int getSize_impl() override
        {
            int size {0};
            for (int enumerate = 0; const auto& entry : directory_)
            {   
                size += entry->getSize(); // Entry : File or Directory
                enumerate++; // 使ってない
            }
            return size;
        }

        virtual void add(shared_ptr<Entry> entry) override
        {
            directory_.emplace_back(entry);
        }
    };
}
#endif