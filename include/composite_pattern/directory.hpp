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
    protected:
        string name_;
        vector<shared_ptr<Entry>> directory_;

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

        virtual string getClassName_impl() override
        {
            return "Directory";
        }

    public:
        Directory(const string& name) : name_(name) 
        {}
        virtual ~Directory() {}

        virtual void add(shared_ptr<Entry> entry) override
        {
            directory_.emplace_back(entry);
        }

        virtual vector<shared_ptr<Entry>>& entries() override
        {
            return directory_; // TODO: 非constな参照を一時オブジェクト(return std::begin(directory_))で初期化できない.(※左辺値である必要がある)
        }
    };
}
#endif