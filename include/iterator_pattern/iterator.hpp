#ifndef ITERATOR_ITERATOR_HPP
#define ITERATOR_ITERATOR_HPP

namespace Is
{
    class Object;

    class Iterator
    {
    public:
        virtual bool hasNext() = 0;
        virtual Object next() = 0;
    };
}
#endif
