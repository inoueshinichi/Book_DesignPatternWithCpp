#ifndef ITERATOR_ITERATOR_HPP
#define ITERATOR_ITERATOR_HPP

namespace Is
{
    class Iterator
    {
    public:
        virtual bool hasNext() = 0;
        virtual void* next() = 0;
    };
}
#endif
