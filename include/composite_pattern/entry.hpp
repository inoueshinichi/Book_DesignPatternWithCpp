#ifndef COMPOSITE_ENTRY_HPP
#define COMPOSITE_ENTRY_HPP

#include "../common.hpp"
#include "../exception.hpp"

#include <string>
#include <sstream>
#include <memory>

namespace Is
{
    using std::string;
    using std::stringstream;
    using std::shared_ptr;

    class DP_API Entry
    {
    protected:
        virtual void printList_impl(const string& prefix) = 0;
        virtual string getName_impl() = 0;
        virtual int getSize_impl() = 0;
        virtual string getClassName_impl() = 0;

    public:
        Entry() {}
        virtual ~Entry() {}

        virtual void add(shared_ptr<Entry> entry) //throw(Exception)
        {
            IS_ERROR(error_code::not_implemented, "Entry class can NOT implement add(unique_ptr<Entry>&& entry).");
        }

        virtual vector<shared_ptr<Entry>>& entries()
        {
            IS_ERROR(error_code::not_implemented, "Element class can NOT implement iterator().");
        }

        void printList(const string& prefix = "")
        {
            this->printList_impl(prefix);
        }

        string getName()
        {
            return this->getName_impl();
        }

        int getSize()
        {
            return this->getSize_impl();
        }

        string toString()
        {
            stringstream ss;
            ss << getName() << " (" << getSize() << ")";
            return ss.str();
        }

        string getClassName()
        {
            return this->getClassName_impl();
        }
    };
}
#endif