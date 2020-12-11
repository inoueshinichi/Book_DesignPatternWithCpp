#ifndef ITERATOR_AGGREGATE_HPP
#define ITERATOR_AGGREGATE_HPP

#include <memory>

namespace Is
{
    using std::shared_ptr;
    class Iterator;

    class Aggregate
    {
    public:
        virtual shared_ptr<Iterator> iterator() = 0;
    };
}
#endif
