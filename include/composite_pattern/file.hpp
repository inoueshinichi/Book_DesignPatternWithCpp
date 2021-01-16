#ifndef COMPOSITE_FILE_HPP
#define COMPOSITE_FILE_HPP

#include "../common.hpp"
#include "entry.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API File : public Entry
    {
    protected:
        string name_;
        int size_;

        virtual void printList_impl(const string& prefix)
        {
            stringstream ss;
            ss << prefix << "/" << toString() << std::endl;
            std::cout << ss.str();
        }

        virtual string getName_impl() override
        {
            return name_;
        }

        virtual int getSize_impl() override
        {
            return size_;
        }

        virtual string getClassName_impl() override
        {
            return "File";
        }

    public:
        File(const string& name, int size)
            : name_(name), size_(size)
        {}
        virtual ~File() {}
    };
}
#endif