#ifndef VISITOR_ELEMENT_HPP
#define VISITOR_ELEMENT_HPP

#include "../common.hpp"
#include "../exception.hpp"

#include <memory>
#include <vector>

namespace Is
{
    using std::shared_ptr;
    using std::vector;

    class Visitor;
    class Entry;

    class DP_API Element
    {
    public:
        virtual void accept(shared_ptr<Visitor> visitor) = 0;
    };
}
#endif