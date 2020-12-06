#ifndef ITERATOR_BOOL_HPP
#define ITERATOR_BOOL_HPP

#include "object.hpp"

#include <string>

namespace Is
{
    using std::string;

    class Book : public Object
    {
        string name_;

    public:
        Book(const string& name) : name_(name) {}
        string getName() { return name_; }
    };
}
#endif
