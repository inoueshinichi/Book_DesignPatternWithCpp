#ifndef ITERATOR_AGGREGATE_HPP
#define ITERATOR_AGGREGATE_HPP

namespace Is
{
    class Iterator;

    class Aggregate
    {
    public:
        virtual Iterator iterator() = 0;
    };
}
#endif
